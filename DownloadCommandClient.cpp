#include "DownloadCommandClient.h"
void DownloadCommandClient::execute() {
    SocketIO scio(sock);
    string serverStr;
    dio = &scio;
    StandardIO sdio;
    vector<string> vs;
    serverStr = dio->read();
    if(serverStr == "please upload data" || serverStr == "please classify the data") {
        dio = &sdio;
        dio->write(serverStr);
        return;
    }
    dio = &scio;
    while (serverStr != "Done.") {
        dio->write("ok");
        serverStr = dio->read();
        vs.push_back(serverStr);
    }
    thread t(&DownloadCommandClient::ClassifyOnCommand, this, vs, path);
    t.detach();
    return;
}
void DownloadCommandClient::ClassifyOnCommand(vector<string> vs, string path) {
    ReadFile rf;
    rf.WriteCSVByVector(vs,path,"Classified.csv");
    return;
}