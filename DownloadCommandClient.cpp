#include "DownloadCommandClient.h"
void DownloadCommandClient::execute() {
    string serverStr;
    dio = &scio;
    StandardIO sdio;
    vector<string> vs;
    serverStr = scio.readFive();
    if(serverStr == "please upload data" || serverStr == "please classify the data") {
        dio = &sdio;
        dio->write(serverStr);
        return;
    }
    while (serverStr != "Done.") {
        serverStr = scio.readFive();
        vs.push_back(serverStr);
    }
    ReadFile rf;
    rf.WriteCSVByVector(vs,path,"Classified.csv");
    return;
}