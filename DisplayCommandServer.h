/*
 * Advanced Programming 1 Project
 * Ofir Goldberg - 315141325
 * Omer Groman - 207163452
*/

#ifndef ADVANCED_PROGRAMMING_1_PROJECT_DISPLAYCOMMANDSERVER_H
#define ADVANCED_PROGRAMMING_1_PROJECT_DISPLAYCOMMANDSERVER_H

#include "Command.h"
#include "Data.h"
#include "SocketIO.h"
#include "StandardIO.h"
#include "DefaultIO.h"

class DisplayCommandServer : public Command {
public:
    //pointer to Data class
    Data *data;
    //override execute function
    void execute() override;
    //constructor that takes in a pointer to Data class and assigns it to data
    DisplayCommandServer(Data *d) {
        data = d;
    };
private:
    //default constructor is deleted
    DisplayCommandServer() = default;
};


#endif //ADVANCED_PROGRAMMING_1_PROJECT_DISPLAYCOMMANDSERVER_H
