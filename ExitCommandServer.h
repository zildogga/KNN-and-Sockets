//
// Created by ofir on 1/22/23.
//

#ifndef ADVANCED_PROGRAMMING_1_PROJECT_EXITCOMMANDSERVER_H
#define ADVANCED_PROGRAMMING_1_PROJECT_EXITCOMMANDSERVER_H

#include "Command.h"
#include "SocketIO.h"

class ExitCommandServer: public Command {
public:
    int sock;
    void execute() override;
    ExitCommandServer(int sockNum) {
        sock = sockNum;
    };
private:
    ExitCommandServer() = default;
};

#endif //ADVANCED_PROGRAMMING_1_PROJECT_EXITCOMMANDSERVER_H
