#ifndef MEMBERSENTITY_H
#define MEMBERSENTITY_H

#pragma once
#include <vector>       // container의 일종
#include <iostream>
#include <string>
#include "Memberinfo.h"

class MembersEntity
{
private:
    std::vector<MemberInfo> vecMembersList;  // vector이면서 MemberList를 가지고 있음
    MemberInfo memberInfo;
    FILE *fpDBData;               // FILE의 포인터를 읽어드린다

public:
    MembersEntity();             
    virtual ~MembersEntity();
    void loadMembersInfo();       // Member에 대한 정보값을 Memory에 로딩하겠다
    void addMemberInfo(MemberInfo member);
    void searchMemberInfo(std::string name);
    bool delMemberInfo(int *cardNum);
    void makeToDB();     // Entity의 저장된 Data를 다시 DB로 넘겨준다
    void printMemberInfo(int index);       // Test 용
    void printMemberInfo(std::string name);
    void printMemberInfo(int *cardNum);
    bool findMemberInfo(int *cardNum); 
    bool findMemberInfo(std::string name);

};

#endif