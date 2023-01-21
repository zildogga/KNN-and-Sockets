//
// Created by ofir on 1/21/23.
//

#include "SettingsCommandClient.h"

void SettingsCommandClient::execute() {
    SocketIO scio(sock);
    dio = &scio;
    dio->write("2");
    char* serverStr = dio->read();
    StandardIO sdio;
    dio = &sdio;
    string str1(serverStr);
    dio->write(str1);
    char* userString = dio->read();
    dio = &scio;
    dio->write(userString);
    serverStr = dio->read();
    dio = &sdio;
    string str2(serverStr);
    dio->write(str2);
}