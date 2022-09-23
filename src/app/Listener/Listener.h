#ifndef LISTENER_H
#define LISTENER_H

#pragma once

#include "Controller.h"
#include "CardReader.h"
#include "Monitor.h"
#include "ManageButton.h"

class Listener
{
private:
    Controller *controller;
    ManageButton *modeButton;
    CardReader *rfid;
    uint8_t rfidData[16];

public:
    Listener(Controller *controller);        
    virtual ~Listener();
    void checkEvent();
    bool checkRfid();


};

#endif