//
// Created by omer on 1/22/23.
//

#include "DownloadCommandClient.h"
void DownloadCommandClient::execute() {
    SocketIO scio(sock);
    StandardIO sdio;
    string serverStr;
    string path;
    dio = &scio;
    dio->write("5");
    dio = &sdio;
    path = dio->read();
    dio = &scio;
    vector<string> vs;
    while ((serverStr = dio->read())!= "Done.") {
        vs.push_back(serverStr);
    }
    ReadFile rf;
    rf.WriteCSVByVector(vs,path,"Classified.csv");
    return;
}