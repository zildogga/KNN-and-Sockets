/*
 * Advanced Programming 1 Project
 * Ofir Goldberg - 315141325
 * Omer Groman - 207163452
*/

#ifndef ADVANCED_PROGRAMMING_1_PROJECT_CLASSIFYCOMMANDCLIENT_H
#define ADVANCED_PROGRAMMING_1_PROJECT_CLASSIFYCOMMANDCLIENT_H

#include "Command.h"
#include "SocketIO.h"
#include "StandardIO.h"

class ClassifyCommandClient : public Command {
public:
    // Declare an int variable to store the socket number
    int sock;
    // Declare the execute method, which will be overridden from the base class
    void execute() override;
    // Declare the constructor that takes in a socket number
    ClassifyCommandClient(int sockNum) {
        // Assign the socket number to the class variable
        sock = sockNum;
    };
private:
    // Declare a default constructor, which is private and can only be accessed within the class
    ClassifyCommandClient() = default;
};



#endif //ADVANCED_PROGRAMMING_1_PROJECT_CLASSIFYCOMMANDCLIENT_H
