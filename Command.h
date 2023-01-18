//
// Created by omer on 1/18/23.
//

#ifndef ADVANCED_PROGRAMMING_1_PROJECT_COMMAND_H
#define ADVANCED_PROGRAMMING_1_PROJECT_COMMAND_H
#include "stdio.h"
#include "iostream"
#include "string.h"
#include "DefaultIO.h"
using namespace std;

class Command {
public:
    string description;
    DefaultIO dio;
    virtual void execute();
};


#endif //ADVANCED_PROGRAMMING_1_PROJECT_COMMAND_H
