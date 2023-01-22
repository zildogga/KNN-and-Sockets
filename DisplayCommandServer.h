
#ifndef ADVANCED_PROGRAMMING_1_PROJECT_DISPLAYCOMMANDSERVER_H
#define ADVANCED_PROGRAMMING_1_PROJECT_DISPLAYCOMMANDSERVER_H
#include "Command.h"
#include "Data.h"

class DisplayCommandServer: public Command {
public:
    Data *data;
    void execute() override;
    DisplayCommandServer(Data *d){
        data = d;
    };
private:
    DisplayCommandServer() = default;
};

#endif //ADVANCED_PROGRAMMING_1_PROJECT_DISPLAYCOMMANDSERVER_H
