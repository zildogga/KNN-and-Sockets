/*
 * Advanced Programming 1 Project
 * Ofir Goldberg - 315141325
 * Omer Groman - 207163452
*/

#ifndef ADVANCED_PROGRAMMING_1_PROJECT_CLI_H
#define ADVANCED_PROGRAMMING_1_PROJECT_CLI_H

#include "DistanceClass.h"
#include <sstream>
#include "Command.h"
#include "SettingsCommandClient.h"
#include "UploadCommandClient.h"
#include "ExitCommandClient.h"
#include "ClassifyCommandClient.h"
#include "DisplayCommandClient.h"
#include "DownloadCommandClient.h"
#include "BeforeDownloadCommandClient.h"
#include "thread"
#include "queue"
#include "mutex"

using namespace std;

class CLI {
public:
    // Declaring a member variable 'sock' of type int
    int sock;
    // Declaration of 'start' function which is used to start the CLI
    void start();
    // Declaration of 'downloadCommand' function which is used to download the file
    void downloadCommand(int sock, string path);
    // Constructor that takes an integer as a parameter
    CLI(int sock2) {
        // Assigns the value of the parameter to the member variable 'sock'
        sock = sock2;
    }

private:
    // Default constructor
    CLI() = default;
};


#endif //ADVANCED_PROGRAMMING_1_PROJECT_CLI_H
