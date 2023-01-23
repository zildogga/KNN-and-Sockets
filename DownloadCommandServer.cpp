
#include "DownloadCommandServer.h"

void DownloadCommandServer::execute() {
    string temp;
    SocketIO socio(data->socketNum);
    dio = &socio;
    if (data->trainCSV.empty() || data->testCSV.empty()) {
        dio->write("fiveAssplease upload data");
        return;
    }
    if (data->classified.empty()) {
        dio->write("fiveAssplease classify the data");
        return;
    }
    for (int i = 0; i < data->classified.size(); i++) {
        temp = "fiveAss" + to_string(i + 1) + ',' + data->classified.at(i);
        dio->write(temp);
        this_thread::sleep_for(chrono::milliseconds(100));
    }
    dio->write("fiveAssDone.");
    return;
}