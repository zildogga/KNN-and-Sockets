/*
 * Advanced Programming 1 Project
 * Ofir Goldberg - 315141325
 * Omer Groman - 207163452
*/

#include "DisplayCommandClient.h"

void DisplayCommandClient::execute() {
    //instantiate StandardIO class
    StandardIO sdio;
    //instantiate SocketIO class and pass in a socket
    SocketIO scio(sock);
    //variable to store server string
    string serverStr;
    //variable to store client string
    string clientStr;
    //set dio pointer to scio
    dio = &scio;
    //write "4" to dio
    dio->write("4");
    //read from dio and store in serverStr
    serverStr = dio->read();
    //if serverStr is either "please upload data" or "please classify the data"
    if (serverStr == "please upload data" || serverStr == "please classify the data") {
        //set dio pointer to sdio
        dio = &sdio;
        //write serverStr to dio
        dio->write(serverStr);
        //return
        return;
    }
    //while serverStr is not "Done."
    while (serverStr != "Done.") {
        //set dio pointer to sdio
        dio = &sdio;
        //write serverStr to dio
        dio->write(serverStr);
        //set dio pointer to scio
        dio = &scio;
        //write "ok" to dio
        dio->write("ok");
        //read from dio and store in serverStr
        serverStr = dio->read();
    }
    //set dio pointer to sdio
    dio = &sdio;
    //write "Done." to dio
    dio->write("Done.");
    // read enter from the user for return to main menu
    dio->read();
    //return
    return;
}
