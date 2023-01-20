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
#include "SocketIO.h"
#include "DefaultIO.h"
#include "SettingsCommand.h"

using namespace std;

class Server {
public:
    // function to start server
    int startServer(string serverPort, string fileName);
    // function to accept client connection
    int acceptClient();
    // function to classify data sent by client
    string serverClassify(int clientSock);
    void sendBuffer(char buffer[], int clientSock);
    char *getBuffer(char* buffer,int sock);
    char *checkIfClientCloseConnection(char *buffer, int clientSock);

};

#endif //ADVANCED_PROGRAMMING_1_PROJECT_SERVER_H
