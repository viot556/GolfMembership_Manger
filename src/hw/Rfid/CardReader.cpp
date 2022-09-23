#include "CardReader.h"

CardReader::CardReader(SPI* spi) : mfrc522(spi)         // 부모의 class 생성자에 spi를 넣기 위해 선언
{
    
}

CardReader::~CardReader()
{

}

bool CardReader::isCard()
{
    uint8_t byte = mfrc522_request(PICC_REQALL, rfidData);
    if (byte == CARD_FOUND)
        return true;
    else
        return false;

    return false;

}

DeviceData CardReader::getCardNumber()
{
    mfrc522_get_card_serial(rfidData);
    cardData.devName = "cardReader";
    cardData.devData.clear();   // vector 값  std::vector(int) devData; || clear : 
    for (const auto data : rfidData)     // auto 변수 : 배열자료 => 자동으로 배열자료에 대한 변수를 만들어준다
    {
        cardData.devData.push_back((int)data);
    }
    return cardData;
}

    