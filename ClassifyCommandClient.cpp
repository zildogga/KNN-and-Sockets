/*
 * Advanced Programming 1 Project
 * Ofir Goldberg - 315141325
 * Omer Groman - 207163452
*/

#include "ClassifyCommandClient.h"

void ClassifyCommandClient::execute() {
    // Declare an object of StandardIO class
    StandardIO sdio;
    // Declare an object of SocketIO class
    SocketIO scio(sock);
    // Declare a string variable to store the server string
    string serverStr;
    // Point the dio pointer to the scio object
    dio = &scio;
    // Write "3" to the connected socket
    dio->write("3");
    // Read the response from the server and store it in serverStr variable
    serverStr = dio->read();
    // Check if the response from the server is "input was not a number"
    if (serverStr == "input was not a number") {
        // If true, update the serverStr variable with "wrong file format, please upload again"
        serverStr = "wrong file format, please upload again";
    }
    // Point the dio pointer to the sdio object
    dio = &sdio;
    // Write the serverStr variable to the standard output
    dio->write(serverStr);
}
