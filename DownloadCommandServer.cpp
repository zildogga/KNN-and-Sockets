
#include "DownloadCommandServer.h"

void DownloadCommandServer::execute() {
    string temp;
    SocketIO socio(data->socketNum);
    dio = &socio;
    for (int i = 0; i < data->classified.size(); i++) {
        temp = "fiveAss" + to_string(i + 1) + ',' + data->classified.at(i);
        dio->write(temp);
        dio->read();
    }
    dio->write("fiveAssDone.");
    return;
}