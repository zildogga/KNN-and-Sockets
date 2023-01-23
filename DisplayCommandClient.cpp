//
// Created by omer on 1/22/23.
//

#include "DisplayCommandClient.h"
void DisplayCommandClient::execute() {
    StandardIO sdio;
    string serverStr;
    string clientStr;
    dio = &scio;
    dio->write("4");
    serverStr = scio.read2();
    if(serverStr == "please upload data" || serverStr == "please classify the data") {
        dio = &sdio;
        dio->write(serverStr);
        return;
    }
    while(serverStr != "Done.") {
        dio = &sdio;
        dio->write(serverStr);
        serverStr = scio.read2();
        dio = &scio;
        dio->write("ok");
    }
    dio = &sdio;
    dio->write("Done.");
    return;
}