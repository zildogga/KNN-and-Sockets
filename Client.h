//
// Created by ofir on 12/31/22.
//

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
    int createClient(char *ipAddress, string portNum);
    int vectorToCharArray(const std::vector<double>& vec, char* charArray);
};


#endif //ADVANCED_PROGRAMMING_1_PROJECT_CLIENT_H
