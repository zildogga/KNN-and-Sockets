//
// Created by omer on 1/18/23.
//

#include "UploadCommandServer.h"

void UploadCommandServer::execute() {
    SocketIO socketIO(data->socketNum);
    dio = &socketIO;
    // first upload
    dio->write("Please upload your local train CSV file.");
    string currentLine1;
    list<string> trainCSVList;
    while ((currentLine1 = dio->read()) != "endOfFile") {
        trainCSVList.push_back(currentLine1);
    }
    if (trainCSVList.empty()) {
        dio->write("invalid input");
        return;
    }
    vector<vector<string>> trainCSVVector;
    ReadFile rf1;
    trainCSVVector = rf1.ReadCSVByList(trainCSVList);
    data->trainCSV = trainCSVVector;
    dio->write("Upload complete."
               "\nPlease upload your local test CSV file.");

    // second upload
    string currentLine2;
    list<string> testCSVList;
    while ((currentLine2 = dio->read()) != "endOfFile") {
        testCSVList.push_back(currentLine2);
    }
    if (testCSVList.empty()) {
        dio->write("invalid input");
        return;
    }
    vector<vector<string>> testCSVVector;
    ReadFile rf2;
    testCSVVector = rf2.ReadCSVByList(testCSVList);
    data->testCSV = testCSVVector;
    dio->write("Upload complete.");
}
