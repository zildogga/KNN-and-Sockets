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
#include "SettingsCommandServer.h"
#include <thread>
#include <unistd.h>
#include <vector>
#include "Data.h"
#include "UploadCommandServer.h"
#include "ExitCommandServer.h"
#include "ClassifyCommandServer.h"
#include "DisplayCommandServer.h"
#include "DownloadCommandServer.h"
using namespace std;

class Server {
public:
    // function to start server
    static int startServer(string serverPort, string fileName);
    // function to accept client connection
    static int menu(int client_sock, Data *data);
    static int getSockPerClient();
    // function to classify data sent by client
    static string serverClassify(int clientSock);
    static void sendBuffer(char buffer[], int clientSock);
    static char *getBuffer(char* buffer,int sock);
    static char *checkIfClientCloseConnection(char *buffer, int clientSock);
};

#endif //ADVANCED_PROGRAMMING_1_PROJECT_SERVER_H
