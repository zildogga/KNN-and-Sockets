
#include "DisplayCommandServer.h"
void DisplayCommandServer::execute() {
    SocketIO socio(data->socketNum);
    dio = &socio;
    string temp;
    if (data->trainCSV.empty() || data->testCSV.empty()) {
        dio->write("please upload data");
        return;
    }
    if (data->classified.empty()) {
        dio->write("please classify the data");
        return;
    }
    for (int i = 0; i < data->classified.size(); i++) {
        temp = to_string(i) + " " + data->classified[i];
        dio->write(temp);
    }
    return;
}