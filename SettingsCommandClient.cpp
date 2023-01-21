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
    string serverStr = dio->read();
    cout << "4" << endl;
    StandardIO sdio;
    cout << "5" << endl;
    dio = &sdio;
    cout << "6" << endl;
    dio->write(serverStr);
    cout << "8" << endl;
    string userString = dio->read();
    cout << "9" << endl;
    dio = &scio;
    cout << "10" << endl;
    dio->write(userString);
    cout << "11" << endl;
    string serverStr2 = dio->read();
    cout << "12" << endl;
    StandardIO sdio2;
    dio = &sdio2;
    cout << "13" << endl;
    cout << "14" << endl;
    dio->write(serverStr2);
    cout << "finished this fucking shit" << endl;
}