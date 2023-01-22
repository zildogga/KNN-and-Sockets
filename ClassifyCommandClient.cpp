//
// Created by omer on 1/22/23.
//

#include "ClassifyCommandClient.h"
void ClassifyCommandClient::execute() {
    SocketIO scio(sock);
    StandardIO sdio;
    string serverStr;
    dio = &scio;
    dio->write("3");
    serverStr = dio->read();
    dio = &sdio;
    dio->write(serverStr);
}