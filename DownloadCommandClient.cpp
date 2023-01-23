#include "DownloadCommandClient.h"
void DownloadCommandClient::execute() {
    string serverStr;
    dio = &scio;
    vector<string> vs;
    cout << "before while" << endl;
    while ((serverStr = scio.readFive()) != "Done.") {
        cout << "before ok" << endl;
        scio.write("ok");
        cout << "after ok" << endl;
        vs.push_back(serverStr);
    }
    cout << "after while" << endl;
    ReadFile rf;
    rf.WriteCSVByVector(vs,path,"Classified.csv");
    return;
}