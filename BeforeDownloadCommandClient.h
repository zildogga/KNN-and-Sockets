/*
 * Advanced Programming 1 Project
 * Ofir Goldberg - 315141325
 * Omer Groman - 207163452
*/

#ifndef ADVANCED_PROGRAMMING_1_PROJECT_BEFOREDOWNLOADCOMMANDCLIENT_H
#define ADVANCED_PROGRAMMING_1_PROJECT_BEFOREDOWNLOADCOMMANDCLIENT_H

#include "Command.h"
#include "SocketIO.h"
#include "StandardIO.h"

class BeforeDownloadCommandClient : public Command {
public:
    // declare a pointer to a string object named path
    string *path;
    // declare an integer variable named sock
    int sock;
    // declare a function named execute which overrides a function of the same name in the base class
    void execute() override;
    // constructor taking an integer and a string pointer as parameters, initializing the sock and path member variables
    BeforeDownloadCommandClient(int sockNum, string *pathConstructor) {
        sock = sockNum;
        path = pathConstructor;
    };
private:
    // default constructor is private, so it can't be called from outside the class
    BeforeDownloadCommandClient() = default;
};



#endif //ADVANCED_PROGRAMMING_1_PROJECT_BEFOREDOWNLOADCOMMANDCLIENT_H
