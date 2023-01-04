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


class Client {
public:
    // createClient function creates a socket and connects to a server
    int createClient(char *ipAddress, string portNum);
    // vectorToCharArray function converts a vector of doubles to a char array
    //int vectorToCharArray(const std::vector<double>& vec, char* charArray);
};



#endif //ADVANCED_PROGRAMMING_1_PROJECT_CLIENT_H
