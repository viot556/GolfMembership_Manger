#ifndef CARDREADER_H
#define CARDREADER_H

#pragma once

#include <iostream>
#include "mfrc522.h"
#include "DeviceData.h"


class CardReader : public mfrc522    // 상속
{
private:
    uint8_t rfidData[16];
    DeviceData cardData;

public:
    CardReader(SPI* spi);
    ~CardReader();
    bool isCard();
    DeviceData getCardNumber();

};

#endif