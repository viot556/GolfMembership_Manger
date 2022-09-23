#ifndef CONTROLLER_H
#define CONTROLLER_H

#pragma once

#include "Monitor.h"
#include "DeviceData.h"
#include "MemManageService.h"

class Controller
{
private:
    Monitor *monitor;
    MemManageService *memManageService;


public:
    Controller(MemManageService *memManageService);
    virtual ~Controller();
    void updateEvent(DeviceData data);



};

#endif