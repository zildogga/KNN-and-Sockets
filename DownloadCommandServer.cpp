
#include "DownloadCommandServer.h"

void DownloadCommandServer::execute() {
    string temp;
    SocketIO socio(data->socketNum);
    dio = &socio;
    if (data->trainCSV.empty() || data->testCSV.empty()) {
        dio->write("please upload data");
        return;
    }
    if (data->classified.empty()) {
        dio->write("please classify the data");
        return;
    }
    for (int i = 0; i < data->classified.size(); i++) {
        temp = to_string(i + 1) + ',' + data->classified.at(i);
        dio->write(temp);
        dio->read();
    }
    dio->write("Done.");
    return;
}