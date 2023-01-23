//
// Created by ofir on 1/21/23.
//

#include "SettingsCommandClient.h"

void SettingsCommandClient::execute() {
    dio = &scio;
    dio->write("2");
    string serverStr = scio.read2();
    StandardIO sdio;
    dio = &sdio;
    dio->write(serverStr);
    string userString = dio->read();
    dio = &scio;
    dio->write(userString);
    string serverStr2 = scio.read2();
    if(serverStr2 == "User pressed enter") {
        return;
    }
    StandardIO sdio2;
    dio = &sdio2;
    dio->write(serverStr2);
}