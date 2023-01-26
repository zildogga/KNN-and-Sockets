/*
 * Advanced Programming 1 Project
 * Ofir Goldberg - 315141325
 * Omer Groman - 207163452
*/

#include "CLI.h"

void CLI::start() {
    // infinite loop
    while (true) {
        // Declare buffer with size of SIZE_OF_BUFFER
        char buffer[SIZE_OF_BUFFER];
        // Declare an object of SocketIO class, which takes in the socket number
        SocketIO scio(sock);
        // Copy the string from the scio.read() method to the buffer
        strcpy(buffer, scio.read().c_str());
        // Check if the buffer is null
        if (buffer == nullptr) {
            break;
        } else if (buffer == "") {
            // Close the socket if the buffer is empty
            close(sock);
            return;
        } else if (strcmp(buffer, "close") == 0) {
            // Close the socket if the buffer is "close"
            close(sock);
            return;
        } else {
            // print the buffer
            cout << buffer << endl;
            // Declare the string choice for the user choice
            string choice;
            // take the choise as input from the user
            cin >> choice;
            if (choice == "1") {
                // Declare an object of UploadCommandClient class, which takes in the socket number
                UploadCommandClient ucc(sock);
                // Execute the command
                ucc.execute();
            } else if (choice == "2") {
                // Declare an object of SettingsCommandClient class, which takes in the socket number
                SettingsCommandClient scc(sock);
                // Execute the command
                scc.execute();
            } else if (choice == "3") {
                // Declare an object of ClassifyCommandClient class, which takes in the socket number
                ClassifyCommandClient scc(sock);
                // Execute the command
                scc.execute();
            } else if (choice == "4") {
                // Declare an object of DisplayCommandClient class, which takes in the socket number
                DisplayCommandClient dcc(sock);
                // Execute the command
                dcc.execute();
            } else if (choice == "5") {
                // Declare a string variable to store the path
                string path;
                // Declare an object of BeforeDownloadCommandClient class, which takes in the socket number and path
                BeforeDownloadCommandClient bdcc(sock, &path);
                // Execute the command
                bdcc.execute();
                // call the downloadCommand function with the sock number and path as input
                downloadCommand(sock, path);
            } else if (choice == "8") {
                // Declare an object of ExitCommandClient class, which takes in the socket number
                ExitCommandClient ecc(sock);
                // Execute the command
                ecc.execute();
                break;
            } else {
                // print wrong option
                scio.write("wrong option");
                cout << "wrong option" << endl;
                scio.read();
            }
        }
    }
    // close socket
    close(sock);
    return;
}

void CLI::downloadCommand(int sock, string path) {
    // Declare an object of DownloadCommandClient class, which takes in the sock and path
    DownloadCommandClient dwcc(sock, path);
    // Execute the command
    dwcc.execute();
}
