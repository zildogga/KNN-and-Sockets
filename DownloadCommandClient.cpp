#include "DownloadCommandClient.h"
void DownloadCommandClient::execute() {
    string serverStr;
    dio = &scio;
    vector<string> vs;
    while ((serverStr = scio.readFive())!= "Done.") {
        vs.push_back(serverStr);
    }
    ReadFile rf;
    rf.WriteCSVByVector(vs,path,"Classified.csv");
    return;
}