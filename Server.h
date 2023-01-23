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
    static int startServer(string serverPort);
    static int menu(int client_sock, Data *data);
    static int getSockPerClient(int sockNum);
    static void runDownloadCommand(Data *data);
};

#endif //ADVANCED_PROGRAMMING_1_PROJECT_SERVER_H
