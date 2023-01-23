//
// Created by omer on 1/22/23.
//

#include "DownloadCommandClient.h"
void DownloadCommandClient::execute() {
    SocketIO scio(sock);
    string serverStr;
    dio = &scio;
    vector<string> vs;
    Client c;
    while (c.fiveMsg.empty()) {

    }
    while ((serverStr = c.fiveMsg.front())!= "Done.") {
        vs.push_back(serverStr);
        c.fiveMsg.pop();
        while (c.fiveMsg.empty()) {

        }
    }
    ReadFile rf;
    rf.WriteCSVByVector(vs,path,"Classified.csv");
    return;
}