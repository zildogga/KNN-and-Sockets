#ifndef ADVANCED_PROGRAMMING_1_PROJECT_CLIENT_H
#define ADVANCED_PROGRAMMING_1_PROJECT_CLIENT_H
#include <iostream>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <vector>
#include "DistanceClass.h"
#include <sstream>
#include "Command.h"
#include "SettingsCommandClient.h"
#include "UploadCommandClient.h"
#include "ExitCommandClient.h"
#include "ClassifyCommandClient.h"
#include "DisplayCommandClient.h"
#include "DownloadCommandClient.h"
#include "BeforeDownloadCommandClient.h"
#include "thread"
#include "queue"
#include "mutex"
#include "CLI.h"

#define SIZE_OF_BUFFER 4096


class Client {
public:
    int createClient(char *ipAddress, string portNum);
    void downloadCommand(int sock, string path, SocketIO scio);
    void ReciveMsg(SocketIO scio);
};



#endif //ADVANCED_PROGRAMMING_1_PROJECT_CLIENT_H
