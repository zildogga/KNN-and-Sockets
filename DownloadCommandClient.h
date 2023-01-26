/*
 * Advanced Programming 1 Project
 * Ofir Goldberg - 315141325
 * Omer Groman - 207163452
*/

#ifndef ADVANCED_PROGRAMMING_1_PROJECT_DOWNLOADCOMMANDCLIENT_H
#define ADVANCED_PROGRAMMING_1_PROJECT_DOWNLOADCOMMANDCLIENT_H

#include "Command.h"
#include "Data.h"
#include "SocketIO.h"
#include "StandardIO.h"
#include "DefaultIO.h"
#include "ReadFile.h"

class DownloadCommandClient: public Command {
public:
    //variable to store the socket number
    int sock;
    //variable to store the path
    string path;
    //overridden execute function
    void execute() override;
    //function to classify the data and write it to a file
    void ClassifyOnCommand(vector<string> vs, string path);
    //constructor that takes in the socket number and the path
    DownloadCommandClient(int sockNum, string pathConstructor){
        sock = sockNum;
        path = pathConstructor;
    };
private:
    //default constructor
    DownloadCommandClient() = default;
};



#endif //ADVANCED_PROGRAMMING_1_PROJECT_DOWNLOADCOMMANDCLIENT_H
