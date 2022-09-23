#include "Controller.h"
#include <iostream>

Controller::Controller(MemManageService *memManageService)
{
    monitor = new Monitor();
   // memManageService = new MemManageService();
   this->memManageService = memManageService;
}

Controller::~Controller()
{

}

void Controller::updateEvent(DeviceData data)      // Card ID를 넘겨줘야한다
{
    if (data.devName == "cardReader")
    {
        int cardNumber[5];
        cardNumber[0] = data.devData[0];
        for (int i=0; i<5; i++)
        cardNumber[i] = data.devData[1];

        memManageService->checkCard(cardNumber);
    }

    if (data.devName == "ModeButton")
    {
        memManageService->updateStateEvent("ModeButton");
    }
    // std::cout << data.devName << " : ";
    // for(const auto &data : data.devData)
    // {
    //     std::cout << data << " ";
    // }
    // std::cout << std::endl;
}