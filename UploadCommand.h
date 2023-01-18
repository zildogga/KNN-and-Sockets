//
// Created by omer on 1/18/23.
//

#ifndef ADVANCED_PROGRAMMING_1_PROJECT_UPLOADCOMMAND_H
#define ADVANCED_PROGRAMMING_1_PROJECT_UPLOADCOMMAND_H
#include "Command.h"
#include "StandardIO.h"
#include "DefaultIO.h"
#include "SocketIO.h"
using namespace std;

class UploadCommand: public Command {
public:
    void execute() override;
};


#endif //ADVANCED_PROGRAMMING_1_PROJECT_UPLOADCOMMAND_H
