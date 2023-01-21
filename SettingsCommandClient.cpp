//
// Created by ofir on 1/21/23.
//

#include "SettingsCommandClient.h"

void SettingsCommandClient::execute() {
    SocketIO scio(sock);
    cout << "1" << endl;
    dio = &scio;
    cout << "2" << endl;
    dio->write("2");
    cout << "3" << endl;
    char* serverStr = dio->read();
    cout << "4" << endl;
    StandardIO sdio;
    cout << "5" << endl;
    dio = &sdio;
    cout << "6" << endl;
    string str1(serverStr);
    cout << "7" << endl;
    dio->write(str1);
    cout << "8" << endl;
    char* userString = dio->read();
    cout << "9" << endl;
    dio = &scio;
    cout << "10" << endl;
    dio->write(userString);
    cout << "11" << endl;
    serverStr = dio->read();
    cout << "12" << endl;
    dio = &sdio;
    cout << "13" << endl;
    string str2(serverStr);
    cout << "14" << endl;
    dio->write(str2);
    cout << "15" << endl;
}