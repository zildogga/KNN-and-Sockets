#include "DownloadCommandClient.h"
void DownloadCommandClient::execute() {
    string serverStr;
    dio = &scio;
    vector<string> vs;
    cout << "before while" << endl;
    scio.write("ok");
    while ((serverStr = scio.readFive()) != "Done.") {
        cout << "trying to send ok in download" << endl;
        scio.write("ok");
        cout << "sent ok in download" << endl;
        vs.push_back(serverStr);
        cout <<"before display readFive the buffer is empty : " << scio.fiveMsg->empty();
    }
    cout << "after while" << endl;
    ReadFile rf;
    rf.WriteCSVByVector(vs,path,"Classified.csv");
    return;
}