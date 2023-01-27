/*
 * Advanced Programming 1 Project
 * Ofir Goldberg - 315141325
 * Omer Groman - 207163452
*/

#ifndef ADVANCED_PROGRAMMING_1_PROJECT_SETTINGSCOMMANDSERVER_H
#define ADVANCED_PROGRAMMING_1_PROJECT_SETTINGSCOMMANDSERVER_H

#include "Command.h"
#include "StandardIO.h"
#include "SocketIO.h"
#include "string.h"
#include "stdio.h"

using namespace std;

class SettingsCommandServer : public Command {
public:
    // Declare a pointer variable "data" that points to an instance of "Data"
    Data *data;
    // Declare a function "execute" that overrides the "execute" function in the "Command" class
    void execute() override;
    // Declare a constructor that takes in a pointer to an instance of "Data" and assigns it to the "data" variable
    SettingsCommandServer(Data *d) {
        data = d;
    };
};


#endif //ADVANCED_PROGRAMMING_1_PROJECT_SETTINGSCOMMANDSERVER_H
