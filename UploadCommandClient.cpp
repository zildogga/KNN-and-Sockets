/*
 * Advanced Programming 1 Project
 * Ofir Goldberg - 315141325
 * Omer Groman - 207163452
*/

#include "UploadCommandClient.h"

void UploadCommandClient::execute() {
    // Initialize StandardIO and SocketIO objects
    StandardIO stio;
    SocketIO scio(sock);
    string serverStr = "";
    string ClientStr = "";
    // Set dio to point to scio
    dio = &scio;
    // Send "1" to the server
    dio = &scio;
    dio->write("1");
    // Read the server's response
    serverStr = dio->read();
    // Set dio to point to stio
    dio = &stio;
    // Write the server's response to the standard output
    dio->write(serverStr);
    // Read the client's response
    ClientStr = dio->read();
    // Set dio to point to scio
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
            dio->read();
        }
        // This line closes the CSV file
        file.close();
        dio->write("endOfFile");
        serverStr = dio->read();
        dio = &stio;
        dio->write(serverStr);
        if (serverStr == "invalid input") {
            return;
        }
    } else {
        dio->write("endOfFile");
        serverStr = dio->read();
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
            dio->read();
        }
        // This line closes the CSV file
        file2.close();
        dio->write("endOfFile");
        serverStr = dio->read();
        dio = &stio;
        dio->write(serverStr);
        if (serverStr == "invalid input") {
            return;
        }
    } else {
        dio->write("endOfFile");
        serverStr = dio->read();
        dio = &stio;
        dio->write(serverStr);
        return;
    }
    return;
}