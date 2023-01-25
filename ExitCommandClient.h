//
// Created by omer on 1/18/23.
//

#ifndef ADVANCED_PROGRAMMING_1_PROJECT_EXITCOMMANDCLIENT_H
#define ADVANCED_PROGRAMMING_1_PROJECT_EXITCOMMANDCLIENT_H
#include "Command.h"
#include "SocketIO.h"

class ExitCommandClient: public Command {
public:
    int sock;
    void execute() override;
    ExitCommandClient(int sockNum) {
        sock = sockNum;
    };
private:
    ExitCommandClient() = default;
};


#endif //ADVANCED_PROGRAMMING_1_PROJECT_EXITCOMMANDCLIENT_H
