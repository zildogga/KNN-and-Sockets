//
// Created by omer on 1/18/23.
//

#ifndef ADVANCED_PROGRAMMING_1_PROJECT_DEFAULTIO_H
#define ADVANCED_PROGRAMMING_1_PROJECT_DEFAULTIO_H
#include "Command.h"
#include "stdio.h"
#include "iostream"
#include "string.h"
using namespace std;

class DefaultIO{
public:
    virtual string read();
    virtual void write(string);
};


#endif //ADVANCED_PROGRAMMING_1_PROJECT_DEFAULTIO_H
