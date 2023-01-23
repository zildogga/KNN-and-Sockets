
#include "DownloadCommandServer.h"

void DownloadCommandServer::execute() {
    string temp;
    SocketIO socio(data->socketNum);
    dio = &socio;
    for (int i = 0; i < data->classified.size(); i++) {
        temp = "fiveAss" + to_string(i + 1) + ',' + data->classified.at(i);
        cout << "writing in download" << endl;
        dio->write(temp);
        cout << "waiting for response in download" << endl;
        dio->read();
        cout << "got response in download" << endl;
    }
    cout << "writing done in download" << endl;
    dio->write("fiveAssDone.");
    return;
}