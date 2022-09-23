#include "MembersEntity.h"
#include <string.h>

MembersEntity::MembersEntity()
{
    loadMembersInfo();
}

MembersEntity::~MembersEntity()
{

}

void MembersEntity::loadMembersInfo()
{
    fpDBData = fopen("memberLists.bin", "r");   // "r+" : read + write, fopen : 파일 열기  || 파일이 없다면 NULL을 보내줌
    if (fpDBData == NULL)
    {
        fprintf(stderr, "file open error!\n");   //stderr : standard error를 모니터에 출력하겠다
        return;
    }
    while (fread(&memberInfo, sizeof(MemberInfo), 1, fpDBData))   // fread = File read
    {     
        vecMembersList.push_back(memberInfo);
    }
    fclose(fpDBData);      // 파일 닫아주는 작업 항상 필요  
}

void MembersEntity::printMemberInfo(int index)
{
    if (index > vecMembersList.size())
    {
        fprintf(stderr, "out of range member count\n");
        return;
    }
    printf("%04d, %s, %s, %s, %0x-%0x-%0x-%0x-%0x\n",
            vecMembersList[index].id,
            vecMembersList[index].name,
            vecMembersList[index].address,
            vecMembersList[index].phoneNumber,
            vecMembersList[index].cardNum[0],
            vecMembersList[index].cardNum[1],
            vecMembersList[index].cardNum[2],
            vecMembersList[index].cardNum[3],
            vecMembersList[index].cardNum[4]
          );
}

void MembersEntity::printMemberInfo(std::string name)   // overload
{
    for (const auto &member : vecMembersList)     // MembersList의 값을 자동으로 읽는다
    {
        if (strcmp(member.name, name.c_str()) == 0)     // .c_str : char 형의 문자열을 string 형으로 바꿔준다, strcmp : string compare -> string 값 비교
        {
            printMemberInfo(member.id);
            return;
        }
    }
}

void MembersEntity::printMemberInfo(int *cardNum)
{
    for (const auto &member : vecMembersList)     // MembersList의 값을 자동으로 읽는다
    {
        if (memcmp(member.cardNum, cardNum, sizeof(member.cardNum)) == 0)     // .c_str : char 형의 문자열을 string 형으로 바꿔준다, strcmp : string compare -> string 값 비교
        {
            printMemberInfo(member.id);
            return;
        }
    }
}


bool MembersEntity::findMemberInfo(std::string name)   // 등록되어 있는 카드면 true, 등록이 안된 카드면 false
{
    for (const auto &member : vecMembersList)     // MembersList의 값을 자동으로 읽는다
    {
        if (strcmp(member.name, name.c_str()) == 0)     // .c_str : char 형의 문자열을 string 형으로 바꿔준다, strcmp : string compare -> string 값 비교
        {
            printMemberInfo(member.id);
            return true;
        }
    }
    return false;
}

void MembersEntity::searchMemberInfo(std::string name)
{
    for (const auto &member : vecMembersList)
    {
        if (strcmp(member.name, name.c_str()) == 0)
        {
            
        }
    }
}

bool MembersEntity::findMemberInfo(int *cardNum)
{
    for (const auto &member : vecMembersList)
    {
        if (memcmp(member.cardNum, cardNum, sizeof(member.cardNum)) == 0)   //sizeof(member.cardNum) : ()의 size 만큼 비교하겠다
        {
            return true;
        }
    }
    return false;
}

void MembersEntity::addMemberInfo(MemberInfo member)
{
    vecMembersList.push_back(member);
}

bool MembersEntity::delMemberInfo(int *cardNum)
{
    std::vector<MemberInfo>::iterator itrMember;    //
    itrMember = vecMembersList.begin();    // vec의 첫번째 주소를 준다 => pointer 변수와 비슷
    for (itrMember; itrMember !=vecMembersList.end(); itrMember++)
    {
        if (memcmp(itrMember->cardNum, cardNum, sizeof(itrMember->cardNum)) == 0)
        {
             vecMembersList.erase(itrMember);       // .clear : 모든 정보를 삭제
             return true;
        }  
    } 

    return false;     
}

void MembersEntity::makeToDB()
{
    // file open 
    // vecMembersList의 배열을 하나씩 read
    // vecMembersList값을 file에 vecMembersList 값 끝까지 write
    // file close
    fpDBData = fopen("memberLists.bin", "w");   // w : 덮어씌우기
    FILE *fpDBData2 = fopen("memberLists.txt", "w");
    if (fpDBData == NULL)
    {
        fprintf(stderr, "file open error!\n");   
        return;
    }
    for (const auto &member : vecMembersList)
    {
        fwrite(&member, sizeof(member), 1, fpDBData);
        fprintf(fpDBData2, "%05d, %s\n", member.id, member.name);
    }
    fclose(fpDBData);   
    fclose(fpDBData2);

}