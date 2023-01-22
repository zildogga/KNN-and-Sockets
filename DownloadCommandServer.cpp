
#include "DownloadCommandServer.h"
void DownloadCommandServer::execute() {
    SocketIO socio(data->socketNum);
    dio = &socio;
    dio->write("please enter path for saving the classifying CSV file");
    for(int i = 0; i < data->classified.size(); i++) {
        dio->write(data->classified.at(i));
    }
    dio->write("Done.");
    return;
}