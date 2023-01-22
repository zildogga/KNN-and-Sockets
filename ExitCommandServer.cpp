//
// Created by ofir on 1/22/23.
//

#include "ExitCommandServer.h"
void ExitCommandServer::execute() {
    close(sock);
    return;
}