/*
 * Advanced Programming 1 Project
 * Ofir Goldberg - 315141325
 * Omer Groman - 207163452
*/

#include "ExitCommandServer.h"
void ExitCommandServer::execute() {
    // close socket
    close(sock);
    return;
}