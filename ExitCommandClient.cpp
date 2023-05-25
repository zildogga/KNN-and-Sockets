/*
 * Advanced Programming 1 Project
 * Ofir Goldberg - 315141325
 * Omer Groman - 207163452
*/

#include "ExitCommandClient.h"

void ExitCommandClient::execute() {
    //Socket IO object
    SocketIO scio(sock);
    //pointer to dio
    dio = &scio;
    //write 8 to socket
    dio->write("8");
    //exit function
    return;
}
