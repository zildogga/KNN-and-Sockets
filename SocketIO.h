//
// Created by omer on 1/18/23.
//

#ifndef ADVANCED_PROGRAMMING_1_PROJECT_SOCKETIO_H
#define ADVANCED_PROGRAMMING_1_PROJECT_SOCKETIO_H
#include "DefaultIO.h"
#include <iostream>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include "Classification.h"
#include "Data.h"

#define SIZE_OF_BUFFER 4096

using namespace std;

class SocketIO: public DefaultIO{
public:
    int sock = 0;
    string read() override;
    void write(string) override;
    SocketIO(int socket);
private:
    SocketIO()= default;
};


#endif //ADVANCED_PROGRAMMING_1_PROJECT_SOCKETIO_H
