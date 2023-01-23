#include "MainServer.h"
#include "Main.h"

// This is the main function
int main(
        // This function takes two arguments as input:
        // - argc: the number of command-line arguments passed to the program
        // - argv: an array of strings containing the command-line arguments
        int argc, char* argv[]
) {
    // check if their more arguments than needed
    if (argc <= 1) {
        // if so print Error message
        cerr << "To much parameters inserted to make line" << endl;
        return -1;
    }
    Server server;
    // args[2] = serverPort
    server.startServer(argv[1]);
}


