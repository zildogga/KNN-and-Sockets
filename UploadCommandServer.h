/*
 * Advanced Programming 1 Project
 * Ofir Goldberg - 315141325
 * Omer Groman - 207163452
*/

#ifndef ADVANCED_PROGRAMMING_1_PROJECT_UPLOADCOMMANDSERVER_H
#define ADVANCED_PROGRAMMING_1_PROJECT_UPLOADCOMMANDSERVER_H

#include "Command.h"
#include "StandardIO.h"
#include "DefaultIO.h"
#include "SocketIO.h"
#include "ReadFile.h"
#include "vector"

using namespace std;

class UploadCommandServer : public Command {
public:
    // Pointer to data object
    Data *data;
    // Overridden execute function
    void execute() override;
    // Constructor that sets data object
    UploadCommandServer(Data *d) {
        data = d;
    };
private:
    // Default constructor
    UploadCommandServer() = default;
};


#endif //ADVANCED_PROGRAMMING_1_PROJECT_UPLOADCOMMANDSERVER_H
