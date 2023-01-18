//
// Created by omer on 1/18/23.
//

#ifndef ADVANCED_PROGRAMMING_1_PROJECT_DISPLAYCOMMAND_H
#define ADVANCED_PROGRAMMING_1_PROJECT_DISPLAYCOMMAND_H
#include "Command.h"

class DisplayCommand: public Command {
public:
    void execute() override;
};


#endif //ADVANCED_PROGRAMMING_1_PROJECT_DISPLAYCOMMAND_H
