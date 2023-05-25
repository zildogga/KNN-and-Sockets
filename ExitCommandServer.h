/*
 * Advanced Programming 1 Project
 * Ofir Goldberg - 315141325
 * Omer Groman - 207163452
*/

#ifndef ADVANCED_PROGRAMMING_1_PROJECT_EXITCOMMANDSERVER_H
#define ADVANCED_PROGRAMMING_1_PROJECT_EXITCOMMANDSERVER_H

#include "Command.h"
#include "SocketIO.h"

class ExitCommandServer : public Command {
public:
    // socket number
    int sock;
    //overriding function
    void execute() override;
    //constructor
    ExitCommandServer(int sockNum) {
        //assign socket number
        sock = sockNum;
    };
private:
    // default constructor
    ExitCommandServer() = default;
};


#endif //ADVANCED_PROGRAMMING_1_PROJECT_EXITCOMMANDSERVER_H
