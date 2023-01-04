//
// Created by omer on 1/4/23.
//

#include "MainServer.h"


#include "Main.h"



// This is the main function
int main(
        // This function takes two arguments as input:
        // - argc: the number of command-line arguments passed to the program
        // - argv: an array of strings containing the command-line arguments
        int argc, char* argv[]
) {

    if (argc <= 2) {
        cerr << "Error" << endl;
        return -1;
    }
    Server server;
    server.startServer(argv[2], argv[1]);
}


