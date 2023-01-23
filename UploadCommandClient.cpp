#include "UploadCommandClient.h"

void UploadCommandClient::execute() {
    StandardIO stio;
    string serverStr = "";
    string ClientStr = "";
    dio = &scio;
    dio->write("1");
    serverStr = scio.read2();
    dio = &stio;
    dio->write(serverStr);
    ClientStr = dio->read();
    dio = &scio;
    string line;
    // This line initializes a new ifstream object using the path to the CSV file
    if (ClientStr[0] != '/') {
        string temp = "/";
        temp.append(ClientStr);
        ClientStr = temp;
    }
    ifstream file(ClientStr);
    // This if block is executed if the CSV file was successfully opened
    if (file.is_open()) {
        // This infinite loop reads the CSV file line by line
        while (getline(file, line)) {
            size_t pos = line.find_last_of(" \t\n\r\f\v");
            if (pos != string::npos) {
                line.erase(pos, 1);
            }
            dio->write(line);
        }
        // This line closes the CSV file
        file.close();
        dio->write("endOfFile");
        serverStr = scio.read2();
        dio = &stio;
        dio->write(serverStr);
    } else {
        dio->write("endOfFile");
        serverStr = scio.read2();
        dio = &stio;
        dio->write(serverStr);
        return;
    }
    dio = &stio;
    string ClientStr2 = dio->read();
    if (ClientStr2[0] != '/') {
        string temp = "/";
        temp.append(ClientStr2);
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
            size_t pos = line2.find_last_of(" \t\n\r\f\v");
            if (pos != string::npos) {
                line2.erase(pos, 1);
            }
            dio->write(line2);
        }
        // This line closes the CSV file
        file2.close();
        dio->write("endOfFile");
        serverStr = scio.read2();
        dio = &stio;
        dio->write(serverStr);
    } else {
        dio->write("endOfFile");
        serverStr = scio.read2();
        dio = &stio;
        dio->write(serverStr);
        return;
    }
    return;
}