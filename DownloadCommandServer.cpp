
#include "DownloadCommandServer.h"
void DownloadCommandServer::execute() {
    string temp;
    SocketIO socio(data->socketNum);
    dio = &socio;
    //dio->write("please enter path for saving the classifying CSV file");
    for(int i = 0; i < data->classified.size(); i++) {
        temp = "fiveAss"+to_string(i + 1) + ',' + data->classified.at(i);
        dio->write(temp);
    }
    dio->write("Done.");
    return;
}