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
    // function to start server
    int startServer(string serverPort, string fileName);
    // function to accept client connection
    int acceptClient();
    // function to classify data sent by client
    string serverClassify(int clientSock);
};

#endif //ADVANCED_PROGRAMMING_1_PROJECT_SERVER_H
