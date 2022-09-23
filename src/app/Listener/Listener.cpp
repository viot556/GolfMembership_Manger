#include "Listener.h"
#include "string.h"

Listener::Listener(Controller *controller)
// : rfid(new CardReader(new SPI(10, 3000000))), controller(new Controller()) // 변수 초기화 방법 중 1 | == mfrc522 *rfid = rfid;
{
    rfid = new CardReader(new SPI(10, 3000000));
    modeButton = new ManageButton(27, "ModeButton");
    //controller = new Controller();
    this->controller = controller;
}

Listener::~Listener()
{
}

void Listener::checkEvent()
{
    if (checkRfid())
    {
        controller->updateEvent(rfid->getCardNumber());      // 배열의 이름 = 주소
    }

    if (modeButton->checkButton())
    {
        controller->updateEvent(modeButton->getButtonData());
    }
}
bool Listener::checkRfid()              // bool = true\false 함수
{
    static unsigned int prevCheckTime = 0;
    if(millis() - prevCheckTime < 1000) 
    {
        return false;
    }
    prevCheckTime = millis();

    if (rfid->isCard()) return true;

    return false;


    // uint8_t byte;
    // if ((byte = rfid->mfrc522_request(PICC_REQALL, rfidData)) == CARD_FOUND)
    // {
    //     memset(rfidData, 0, sizeof(rfidData));     // rfidData에 기존 값이 있을 수 있으므로 이를 초기화 시켜주는 명령
    //     rfid->mfrc522_get_card_serial(rfidData);
    //     return true;
    //     // for (int i = 0; i < 5; i++)
    //     //     printf("%02x", rfidData[i]);
    // }
    
}