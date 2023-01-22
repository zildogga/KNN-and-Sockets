//
// Created by omer on 1/18/23.
//

#ifndef ADVANCED_PROGRAMMING_1_PROJECT_UPLOADCOMMANDSERVER_H
#define ADVANCED_PROGRAMMING_1_PROJECT_UPLOADCOMMANDSERVER_H
#include "Command.h"
#include "StandardIO.h"
#include "DefaultIO.h"
#include "SocketIO.h"
#include "ReadFile.h"
#include "vector"
using namespace std;

class UploadCommandServer: public Command {
public:
    Data *data;
    void execute() override;
    UploadCommandServer(Data *d){
        data = d;
    };
private:
    UploadCommandServer() = default;
};


#endif //ADVANCED_PROGRAMMING_1_PROJECT_UPLOADCOMMANDSERVER_H
