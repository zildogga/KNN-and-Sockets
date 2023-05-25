/*
 * Advanced Programming 1 Project
 * Ofir Goldberg - 315141325
 * Omer Groman - 207163452
*/

#include "SettingsCommandClient.h"

void SettingsCommandClient::execute() {
    // Socket IO object
    SocketIO scio(sock);
    // pointer to dio
    dio = &scio;
    // write 2 to scio
    dio->write("2");
    // read from scio
    string serverStr = dio->read();
    // Standard IO object
    StandardIO sdio;
    // pointer to dio
    dio = &sdio;
    // write to standard IO
    dio->write(serverStr);
    // read from standard IO
    string userString = dio->read();
    // pointer to scio
    dio = &scio;
    // write to scio
    dio->write(userString);
    // read from scio
    string serverStr2 = dio->read();
    // check if user pressed enter
    if (serverStr2 == "User pressed enter") {
        return;
    }
    // Standard IO object
    StandardIO sdio2;
    // pointer to dio
    dio = &sdio2;
    // write to standard IO
    dio->write(serverStr2);
}
