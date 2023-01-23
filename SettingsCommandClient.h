//
// Created by ofir on 1/21/23.
//

#ifndef ADVANCED_PROGRAMMING_1_PROJECT_SETTINGSCOMMANDCLIENT_H
#define ADVANCED_PROGRAMMING_1_PROJECT_SETTINGSCOMMANDCLIENT_H
#include "Command.h"
#include "stdio.h"
#include "StandardIO.h"
#include "SocketIO.h"
#include "string.h"

using namespace std;

class SettingsCommandClient: public Command {
public:
    int sock;
    SocketIO scio;
    void execute() override;
    SettingsCommandClient(int sockNum, SocketIO sc) {
        sock = sockNum;
        scio = sc;
    };
private:
    SettingsCommandClient() = default;
};



#endif //ADVANCED_PROGRAMMING_1_PROJECT_SETTINGSCOMMANDCLIENT_H
