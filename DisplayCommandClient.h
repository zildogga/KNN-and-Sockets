//
// Created by omer on 1/22/23.
//

#ifndef ADVANCED_PROGRAMMING_1_PROJECT_DISPLAYCOMMANDCLIENT_H
#define ADVANCED_PROGRAMMING_1_PROJECT_DISPLAYCOMMANDCLIENT_H
#include "Command.h"
#include "SocketIO.h"
#include "StandardIO.h"

class DisplayCommandClient: public Command{
public:
    int sock;
    void execute() override;
    DisplayCommandClient(int sockNum) {
        sock = sockNum;
    };
private:
    DisplayCommandClient() = default;
};


#endif //ADVANCED_PROGRAMMING_1_PROJECT_DISPLAYCOMMANDCLIENT_H
