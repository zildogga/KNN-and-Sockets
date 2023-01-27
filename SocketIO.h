/*
 * Advanced Programming 1 Project
 * Ofir Goldberg - 315141325
 * Omer Groman - 207163452
*/

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
#include "queue"
#include "thread"
#include "mutex"

#define SIZE_OF_BUFFER 4096

using namespace std;

class SocketIO : public DefaultIO {
public:
    //variable to store the socket number
    int sock = 0;
    //overrides the read function from DefaultIO to read from a socket
    string read() override;
    //overrides the write function from DefaultIO to write to a socket
    void write(string) override;
    //constructor that takes in the socket number
    SocketIO(int socket);

private:
    //default constructor
    SocketIO() = default;
};


#endif //ADVANCED_PROGRAMMING_1_PROJECT_SOCKETIO_H
