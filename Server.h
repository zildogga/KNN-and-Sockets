//
// Created by omer on 12/31/22.
//

#ifndef ADVANCED_PROGRAMMING_1_PROJECT_SERVER_H
#define ADVANCED_PROGRAMMING_1_PROJECT_SERVER_H

#include <iostream>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include "Classification.h"

using namespace std;

class Server {
public:
    int startServer(int serverPort, string fileName);
    int acceptClient();
    string serverClassify(int clientSock);
};


#endif //ADVANCED_PROGRAMMING_1_PROJECT_SERVER_H
