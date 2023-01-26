/*
 * Advanced Programming 1 Project
 * Ofir Goldberg - 315141325
 * Omer Groman - 207163452
*/

#ifndef ADVANCED_PROGRAMMING_1_PROJECT_SETTINGSCOMMANDCLIENT_H
#define ADVANCED_PROGRAMMING_1_PROJECT_SETTINGSCOMMANDCLIENT_H

#include "Command.h"
#include "stdio.h"
#include "StandardIO.h"
#include "SocketIO.h"
#include "string.h"

using namespace std;

class SettingsCommandClient : public Command {
public:
    // socket number
    int sock;
    //overriding function
    void execute() override;
    //constructor
    SettingsCommandClient(int sockNum) {
        //assign socket number
        sock = sockNum;
    };
private:
    // default constructor
    SettingsCommandClient() = default;
};


#endif //ADVANCED_PROGRAMMING_1_PROJECT_SETTINGSCOMMANDCLIENT_H
