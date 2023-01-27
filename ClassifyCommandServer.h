/*
 * Advanced Programming 1 Project
 * Ofir Goldberg - 315141325
 * Omer Groman - 207163452
*/

#ifndef ADVANCED_PROGRAMMING_1_PROJECT_CLASSIFYCOMMANDSERVER_H
#define ADVANCED_PROGRAMMING_1_PROJECT_CLASSIFYCOMMANDSERVER_H

#include "Command.h"
#include "Data.h"
#include "SocketIO.h"
#include "DefaultIO.h"
#include "StandardIO.h"
#include "Classification.h"

class ClassifyCommandServer : public Command {
public:
    // Declare a pointer to a Data object
    Data *data;
    // Declare the execute method, which will be overridden from the base class
    void execute() override;
    // Declare the constructor that takes in a pointer to a Data object
    ClassifyCommandServer(Data *d) {
        // Assign the pointer to the class variable
        data = d;
    };
private:
    // Declare a default constructor, which is private and can only be accessed within the class
    ClassifyCommandServer() = default;
};


#endif //ADVANCED_PROGRAMMING_1_PROJECT_CLASSIFYCOMMANDSERVER_H
