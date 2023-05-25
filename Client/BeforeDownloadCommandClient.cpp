/*
 * Advanced Programming 1 Project
 * Ofir Goldberg - 315141325
 * Omer Groman - 207163452
*/

#include "BeforeDownloadCommandClient.h"

void BeforeDownloadCommandClient::execute() {
    //Initialize StandardIO object
    StandardIO sdio;
    //Initialize SocketIO object with the socket
    SocketIO scio(sock);
    //Declare a string variable
    string serverStr;
    //Assign dio pointer to sdio
    dio = &sdio;
    //Assign the value read from dio to the path variable
    *path = dio->read();
    //Reassign dio pointer to scio
    dio = &scio;
    //Write the value "5" to dio
    dio->write("5");
}
