/*
 * Advanced Programming 1 Project
 * Ofir Goldberg - 315141325
 * Omer Groman - 207163452
*/

#ifndef ADVANCED_PROGRAMMING_1_PROJECT_DOWNLOADCOMMANDSERVER_H
#define ADVANCED_PROGRAMMING_1_PROJECT_DOWNLOADCOMMANDSERVER_H

#include "Command.h"
#include "Data.h"
#include "SocketIO.h"
#include "StandardIO.h"
#include "thread"

class DownloadCommandServer : public Command {
public:
    //pointer to Data
    Data *data;
    //overriding function
    void execute() override;
    //constructor
    DownloadCommandServer(Data *d) {
        //assigning new data to pointer
        data = new Data(d->socketNum, d->k, d->algo, d->trainCSV, d->testCSV, d->classified);
    };
private:
    //default constructor
    DownloadCommandServer() = default;
};



#endif //ADVANCED_PROGRAMMING_1_PROJECT_DOWNLOADCOMMANDSERVER_H
