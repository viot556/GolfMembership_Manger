#include <iostream>
#include "Golf_Membership_Manager.h"
#include "MembersEntity.h"
#include "Listener.h"
#include "Controller.h"
#include "MemManageService.h"
#include "MembersEntity.h"
#include "tcp_server.h"
#include "ComDev.h"
#include <string.h>
#include <thread>


void serverThread(tcp_server *server)
{
    char recvBuff[BUFSIZ];
    int recvLen;

    while (server->waitAccept()>0)
    {
        server->setClientState(true);
        while((recvLen = server->recvData(recvBuff, sizeof(recvBuff))) > 0)
        {
            recvBuff[recvLen] = '\0';
            server->sendData(recvBuff, recvLen);
            printf("received : %s\n", recvBuff);
        }
        server->closeSocket(server->getClientSocket());
        server->setClientState(false);
        printf("close client socket\n");
    }
}
int main(void)
{
    // mfrc522 rfid(new SPI(10, 3000000));             // (CE0의 wPi 번호, spi 통신 속도 = 3MHz)
    // Listener *listener = new Listener(&rfid)
    LCD lcd (new I2C("/dev/i2c-1", 0x27));
    tcp_server *cardTcpServer = new tcp_server(5100);
    ComDev *comDev = new ComDev(cardTcpServer);
    MemManageService *memManageService = new MemManageService(comDev,&lcd);
    Controller *controller = new Controller(memManageService);
    Listener *listener = new Listener(controller);
    std::thread threadfunc(serverThread, cardTcpServer);

    while(1)
    {
        listener->checkEvent();
        delay(50);
    }

    // Golf_Membership_Manager golf_Membership_Manager;

    // golf_Membership_Manager.run();

   

}
/*
    while (1)
    {
        listener->checkEvent();
        delay(1000);
        printf("hihi\n");
    }

*/
