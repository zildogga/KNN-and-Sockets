/*
 * Advanced Programming 1 Project
 * Ofir Goldberg - 315141325
 * Omer Groman - 207163452
*/

#ifndef ADVANCED_PROGRAMMING_1_PROJECT_DEFAULTIO_H
#define ADVANCED_PROGRAMMING_1_PROJECT_DEFAULTIO_H

#include "stdio.h"
#include "iostream"
#include "string.h"

using namespace std;

class DefaultIO {
public:
    // virtual function to read input
    virtual string read() { return ""; };
    // virtual function to write output
    virtual void write(string) {};
};


#endif //ADVANCED_PROGRAMMING_1_PROJECT_DEFAULTIO_H
