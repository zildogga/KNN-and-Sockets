//
// Created by omer on 1/18/23.
//

#include "UploadCommandServer.h"

void UploadCommandServer::execute() {
    SocketIO socketIO(data->socketNum);
    dio = &socketIO;
    // first upload
    dio->write("Please upload your local train CSV file.\n");
    string trainCSV = dio->read();
    // checking
    dio->write("Upload complete\nPlease upload your local test CSV file.\n");

    // second upload
    string test = dio->read();
    dio->write("Upload complete\n");
}
