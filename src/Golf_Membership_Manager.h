#ifndef GOLF_MEMBERSHIP_MANAGER_H
#define GOLF_MEMBERSHIP_MANAGER_H

#pragma once

#include "Listener.h"

class Golf_Membership_Manager
{
private:
    Listener *listener;

public:
    Golf_Membership_Manager();
    virtual ~Golf_Membership_Manager();
    void run();



};

#endif