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
    cout <<"before display read2 the buffer is empty : " << scio.allMsg->empty();
    serverStr = scio.read2();
    if(serverStr == "please upload data" || serverStr == "please classify the data") {
        dio = &sdio;
        dio->write(serverStr);
        return;
    }
    while(serverStr != "Done.") {
        dio = &sdio;
        dio->write(serverStr);
        cout << "trying to send ok in display" << endl;
        scio.write("ok");
        cout << "sent ok in display" << endl;
        cout <<"before display read2 the buffer is empty : " << scio.allMsg->empty();
        serverStr = scio.read2();
    }
    dio = &sdio;
    dio->write("Done.");
    return;
}