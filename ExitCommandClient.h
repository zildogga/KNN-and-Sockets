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
    SocketIO scio;
    void execute() override;
    ExitCommandClient(int sockNum, SocketIO sc) {
        sock = sockNum;
        scio = sc;
    };
private:
    ExitCommandClient() = default;
};


#endif //ADVANCED_PROGRAMMING_1_PROJECT_EXITCOMMANDCLIENT_H
