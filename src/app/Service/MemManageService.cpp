#include "MemManageService.h"
#include <string.h>

MemManageService::MemManageService(ComDev *comDev, LCD *lcd)
{
    membersEntity = new MembersEntity();
    membersManagerState = CARD_READER;
    this->comDev = comDev;
    this->lcd = lcd;
    count = 10000;
}

MemManageService::~MemManageService()
{

}


void MemManageService::updateStateEvent(std::string devName)
{
    char buff[30];
    switch (membersManagerState)
    {
        case CARD_READER:
            if (devName == "ModeButton")
            {   
                
                membersManagerState = CARD_REGISTER;
                printf("changed to Card_Register_State\n");
                sprintf(buff, "Register_State     \n");
                lcd->WriteStringXY(1, 0, buff);
                
            }
        break;

        case CARD_REGISTER:
            if (devName == "ModeButton")
            {   
                
                membersManagerState = CARD_READER;
                printf("changed to Card_Reader_State\n");
                sprintf(buff, "Reader_State     \n");
                lcd->WriteStringXY(1, 0, buff);
            }
        break;
    }
}

void MemManageService::checkCard(int *cardNum)
{
    switch (membersManagerState)
    {
        case CARD_READER:
           
           if (membersEntity->findMemberInfo(cardNum))
           {
                printf("Resgistered Member\n");
                membersEntity->printMemberInfo(cardNum);
                comDev->sendData(cardNum);
           }
           else
           {
                printf("Not resgistered Member\n");
           }
        break;

        case CARD_REGISTER:
            MemberInfo tempMember;
            tempMember.id=count;
            printf("이름을 입력하세요:");
            scanf("%s", &tempMember.name);
            printf("주소를 입력하세요:");
            scanf("%s", &tempMember.address);
            printf("연락처를 입력하세요:");
            scanf("%s", &tempMember.phoneNumber);
            // strcpy(tempMember.name, "LEEHYORYN");
            // strcpy(tempMember.address, "101dong 123Ho");
            // strcpy(tempMember.phoneNumber, "010-9876-5432");
            memcpy(tempMember.cardNum, cardNum, sizeof(tempMember.cardNum));

            

            membersEntity->addMemberInfo(tempMember);
            printf("Member Registered!\n");
            count++;
        break;
    }
}