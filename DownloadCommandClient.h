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
    string path;
    void execute() override;
    void ClassifyOnCommand(vector<string> vs, string path);
    DownloadCommandClient(int sockNum, string pathConstructor){
        sock = sockNum;
        path = pathConstructor;
    };
private:
    DownloadCommandClient() = default;
};


#endif //ADVANCED_PROGRAMMING_1_PROJECT_DOWNLOADCOMMANDCLIENT_H
