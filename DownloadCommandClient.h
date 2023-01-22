//
// Created by omer on 1/22/23.
//

#ifndef ADVANCED_PROGRAMMING_1_PROJECT_DOWNLOADCOMMANDCLIENT_H
#define ADVANCED_PROGRAMMING_1_PROJECT_DOWNLOADCOMMANDCLIENT_H

#include "Command.h"
#include "Data.h"
#include "SocketIO.h"
#include "StandardIO.h"
#include "DefaultIO.h"
#include "ReadFile.h"
class DownloadCommandClient: public Command {
public:
    int sock;
    void execute() override;
    DownloadCommandClient(int sockNum){
        sock = sockNum;
    };
private:
    DownloadCommandClient() = default;
};


#endif //ADVANCED_PROGRAMMING_1_PROJECT_DOWNLOADCOMMANDCLIENT_H
