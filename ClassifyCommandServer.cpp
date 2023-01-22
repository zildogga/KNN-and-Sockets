
#include "ClassifyCommandServer.h"
void ClassifyCommandServer::execute() {
    SocketIO scio(data->socketNum);
    StandardIO stio;
    dio = &scio;
    if(data->trainCSV.empty() || data->testCSV.empty()) {
        dio->write("please upload data");
        return;
    } else {
        Classification cl;
        for (int i = 0; i < data->testCSV.size(); i++) {
            data->classified[i] = cl.classifyTestByTrain(data->testCSV.at(i), data->trainCSV, data->k, data->algo);
        }
        dio->write("classifying data complete");
    }
}