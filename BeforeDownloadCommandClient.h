//
// Created by omer on 1/22/23.
//

#ifndef ADVANCED_PROGRAMMING_1_PROJECT_BEFOREDOWNLOADCOMMANDCLIENT_H
#define ADVANCED_PROGRAMMING_1_PROJECT_BEFOREDOWNLOADCOMMANDCLIENT_H
#include "Command.h"
#include "SocketIO.h"
#include "StandardIO.h"

class BeforeDownloadCommandClient: public Command{
public:
    string* path;
    int sock;
    SocketIO scio;
    void execute() override;
    BeforeDownloadCommandClient(int sockNum,string* pathConstructor, SocketIO sc) {
        sock = sockNum;
        path = pathConstructor;
        scio = sc;
    };
private:
    BeforeDownloadCommandClient() = default;
};


#endif //ADVANCED_PROGRAMMING_1_PROJECT_BEFOREDOWNLOADCOMMANDCLIENT_H
