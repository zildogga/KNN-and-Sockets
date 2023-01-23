//
// Created by omer on 1/18/23.
//

#ifndef ADVANCED_PROGRAMMING_1_PROJECT_SETTINGSCOMMANDSERVER_H
#define ADVANCED_PROGRAMMING_1_PROJECT_SETTINGSCOMMANDSERVER_H
#include "Command.h"
#include "StandardIO.h"
#include "SocketIO.h"
#include "string.h"
#include "stdio.h"
using namespace std;

class SettingsCommandServer: public Command {
public:
    Data *data;
    void execute() override;
    SettingsCommandServer(Data *d){
        data = d;
    };
};


#endif //ADVANCED_PROGRAMMING_1_PROJECT_SETTINGSCOMMANDSERVER_H
