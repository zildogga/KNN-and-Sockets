//
// Created by ofir on 1/21/23.
//

#include "SettingsCommandClient.h"

void SettingsCommandClient::execute() {
    SocketIO scio(sock);
    dio = &scio;
    string serverStr = dio->read();
    StandardIO sdio;
    dio = &sdio;
    string userString = dio->read();
    dio = &scio;
    dio->write(userString);
    serverStr = dio->read();
    dio = &sdio;
    dio->write(serverStr);
}