//
// Created by ofir on 1/21/23.
//

#include "UploadCommandClient.h"
void UploadCommandClient::execute() {
    SocketIO scio(sock);
    StandardIO stio;
    string serverStr = "";
    string ClientStr = "";
    dio = &scio;
    dio->write("1");
    serverStr = dio->read();
    dio = &stio;
    dio->write(serverStr);
    ClientStr = dio->read();
    dio = &scio;
    string line;
    // This line initializes a new ifstream object using the path to the CSV file
    if(ClientStr[0]!='/') {
        string temp = "/";
        temp.append(ClientStr);
        ClientStr = temp;
    }
    ifstream file(ClientStr);
    // This if block is executed if the CSV file was successfully opened
    if (file.is_open()) {
        // This infinite loop reads the CSV file line by line
        while (getline(file, line)) {
            dio->write(line);
        }
        // This line closes the CSV file
        file.close();
        dio->write("endOfFile");
        serverStr = dio->read();
        dio = &stio;
        dio->write(serverStr);
    } else {
        dio->write("endOfFile");
        serverStr = dio->read();
        dio = &stio;
        dio->write(serverStr);
        return;
    }
    dio = &stio;
    string ClientStr2 = dio->read();
    if(ClientStr2[0]!='/') {
        string temp = "/";
        temp.append(ClientStr);
        ClientStr2 = temp;
    }
    dio = &scio;
    string line2;
    // This line initializes a new ifstream object using the path to the CSV file
    ifstream file2(ClientStr2);
    // This if block is executed if the CSV file was successfully opened
    if (file2.is_open()) {
        // This infinite loop reads the CSV file line by line
        while (getline(file2, line2)) {
            dio->write(line2);
        }
        // This line closes the CSV file
        file2.close();
        dio->write("endOfFile");
        serverStr = dio->read();
        dio = &stio;
        dio->write(serverStr);
    } else {
        dio->write("endOfFile");
        serverStr = dio->read();
        dio = &stio;
        dio->write(serverStr);
        return;
    }
    return;
}