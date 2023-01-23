//
// Created by omer on 1/22/23.
//

#ifndef ADVANCED_PROGRAMMING_1_PROJECT_CLASSIFYCOMMANDCLIENT_H
#define ADVANCED_PROGRAMMING_1_PROJECT_CLASSIFYCOMMANDCLIENT_H
#include "Command.h"
#include "SocketIO.h"
#include "StandardIO.h"

class ClassifyCommandClient: public Command{
public:
    int sock;
    SocketIO scio;
    void execute() override;
    ClassifyCommandClient(int sockNum, SocketIO sc) {
        sock = sockNum;
        scio = sc;
    };
private:
    ClassifyCommandClient() = default;
};


#endif //ADVANCED_PROGRAMMING_1_PROJECT_CLASSIFYCOMMANDCLIENT_H
