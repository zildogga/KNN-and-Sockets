/*
 * Advanced Programming 1 Project
 * Ofir Goldberg - 315141325
 * Omer Groman - 207163452
*/

#ifndef ADVANCED_PROGRAMMING_1_PROJECT_EXITCOMMANDCLIENT_H
#define ADVANCED_PROGRAMMING_1_PROJECT_EXITCOMMANDCLIENT_H

#include "Command.h"
#include "SocketIO.h"

class ExitCommandClient : public Command {
public:
    // socket number
    int sock;
    //overriding function
    void execute() override;
    //constructor
    ExitCommandClient(int sockNum) {
        //assign socket number
        sock = sockNum;
    };
private:
    // default constructor
    ExitCommandClient() = default;
};



#endif //ADVANCED_PROGRAMMING_1_PROJECT_EXITCOMMANDCLIENT_H
