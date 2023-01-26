/*
 * Advanced Programming 1 Project
 * Ofir Goldberg - 315141325
 * Omer Groman - 207163452
*/

#ifndef ADVANCED_PROGRAMMING_1_PROJECT_COMMAND_H
#define ADVANCED_PROGRAMMING_1_PROJECT_COMMAND_H

#include "stdio.h"
#include "iostream"
#include "string.h"
#include "DefaultIO.h"

using namespace std;

class Command {
public:
    // A string variable to store a description
    string description;
    // A pointer to a DefaultIO object
    DefaultIO *dio;
    // A pure virtual function that will be overridden by derived classes
    virtual void execute() = 0;
};



#endif //ADVANCED_PROGRAMMING_1_PROJECT_COMMAND_H
