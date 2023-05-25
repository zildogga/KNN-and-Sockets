/*
 * Advanced Programming 1 Project
 * Ofir Goldberg - 315141325
 * Omer Groman - 207163452
*/

#ifndef ADVANCED_PROGRAMMING_1_PROJECT_DISPLAYCOMMANDCLIENT_H
#define ADVANCED_PROGRAMMING_1_PROJECT_DISPLAYCOMMANDCLIENT_H

#include "Command.h"
#include "SocketIO.h"
#include "StandardIO.h"

class DisplayCommandClient : public Command {
public:
    //variable to store socket number
    int sock;
    //override execute function
    void execute() override;
    //constructor that takes in socket number and assigns it to sock
    DisplayCommandClient(int sockNum) {
        sock = sockNum;
    };
private:
    //default constructor is deleted
    DisplayCommandClient() = default;
};



#endif //ADVANCED_PROGRAMMING_1_PROJECT_DISPLAYCOMMANDCLIENT_H
