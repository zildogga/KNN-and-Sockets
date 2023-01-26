/*
 * Advanced Programming 1 Project
 * Ofir Goldberg - 315141325
 * Omer Groman - 207163452
*/

#include "MainClient.h"

// This is the main function
int main(
        // This function takes two arguments as input:
        // - argc: the number of command-line arguments passed to the program
        // - argv: an array of strings containing the command-line arguments
        int argc, char *argv[]
) {
    // check if their more arguments than needed
    if (argc <= 2) {
        // if so print Error message
        cerr << "Error" << endl;
        return -1;
    }

    Client client;
    // convert string ip to char[] ip
    string ipStr = argv[1];
    char ip[ipStr.size() + 1];
    strcpy(ip, ipStr.c_str());
    // args[2] == port number
    string portNum = argv[2];
    // create client
    client.createClient(ip, portNum);
    return 0;
}

