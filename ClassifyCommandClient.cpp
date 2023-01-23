//
// Created by omer on 1/22/23.
//

#include "ClassifyCommandClient.h"
void ClassifyCommandClient::execute() {
    StandardIO sdio;
    string serverStr;
    dio = &scio;
    dio->write("3");
    serverStr = scio.read2();
    dio = &sdio;
    dio->write(serverStr);
}