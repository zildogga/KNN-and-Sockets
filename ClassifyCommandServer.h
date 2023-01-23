//
// Created by omer on 1/18/23.
//

#ifndef ADVANCED_PROGRAMMING_1_PROJECT_CLASSIFYCOMMANDSERVER_H
#define ADVANCED_PROGRAMMING_1_PROJECT_CLASSIFYCOMMANDSERVER_H
#include "Command.h"
#include "Data.h"
#include "SocketIO.h"
#include "DefaultIO.h"
#include "StandardIO.h"
#include "Classification.h"
class ClassifyCommandServer: public Command {
public:
    Data *data;
    void execute() override;
    ClassifyCommandServer(Data *d) {
      data = d;
    };
private:
    ClassifyCommandServer() = default;
};


#endif //ADVANCED_PROGRAMMING_1_PROJECT_CLASSIFYCOMMANDSERVER_H
