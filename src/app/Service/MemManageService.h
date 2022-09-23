#ifndef MEMMANAGESERVICE_H
#define MEMMANAGESERVICE_H

#pragma once
#include <string>
#include <vector>
#include "MembersEntity.h"
#include "Memberinfo.h"
#include "ComDev.h"
#include "LCD.h"

enum {CARD_READER, CARD_REGISTER};

class MemManageService
{
private:
    int membersManagerState;        // State 값이 중요 => 카드 확인 및 등록을 위해
    MembersEntity *membersEntity;
    std::vector<MemberInfo> vecMembersList;
    ComDev *comDev;
    LCD *lcd;
    int count;

public:
    MemManageService(ComDev *comDev, LCD *lcd);
    virtual ~MemManageService();
    void updateStateEvent(std::string devName);    // devName : device Name -> button
    void checkCard(int *cardNum);
    void setComDev(ComDev *comDev);

};

#endif