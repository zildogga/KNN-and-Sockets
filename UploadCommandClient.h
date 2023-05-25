/*
 * Advanced Programming 1 Project
 * Ofir Goldberg - 315141325
 * Omer Groman - 207163452
*/

#ifndef ADVANCED_PROGRAMMING_1_PROJECT_UPLOADCOMMANDCLIENT_H
#define ADVANCED_PROGRAMMING_1_PROJECT_UPLOADCOMMANDCLIENT_H

#include "Command.h"
#include "StandardIO.h"
#include "DefaultIO.h"
#include "SocketIO.h"
#include "Data.h"

using namespace std;

class UploadCommandClient : public Command {
public:
    // declare the variable of type int to hold the socket number
    int sock;
    //override execute function
    void execute() override;
    // constructor
    UploadCommandClient(int sockNum) {
    //initialize the socket number
        sock = sockNum;
    };
private:
    // default constructor
    UploadCommandClient() = default;
};


#endif //ADVANCED_PROGRAMMING_1_PROJECT_UPLOADCOMMANDCLIENT_H
