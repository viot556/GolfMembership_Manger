#include "Golf_Membership_Manager.h"

Golf_Membership_Manager::Golf_Membership_Manager()
// mfrc522 *rfid = new mfrc522(new SPI(10, 3000000))
{
    // rfid = new mfrc522(new SPI (10, 3000000));
    // listener = new Listener(rfid);
    //listener = new Listener();
}

Golf_Membership_Manager::~Golf_Membership_Manager()
{

}

void Golf_Membership_Manager::run()
{
    while(1)
    {
        listener->checkEvent();
        delay(10);
    }
}