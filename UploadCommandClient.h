//
// Created by ofir on 1/21/23.
//

#ifndef ADVANCED_PROGRAMMING_1_PROJECT_UPLOADCOMMANDCLIENT_H
#define ADVANCED_PROGRAMMING_1_PROJECT_UPLOADCOMMANDCLIENT_H
#include "Command.h"
#include "StandardIO.h"
#include "DefaultIO.h"
#include "SocketIO.h"
using namespace std;

class UploadCommandClient: public Command {
public:
    Data *data;
    void execute() override;
    UploadCommandClient(Data *d){
        data = d;
    };
};



#endif //ADVANCED_PROGRAMMING_1_PROJECT_UPLOADCOMMANDCLIENT_H
