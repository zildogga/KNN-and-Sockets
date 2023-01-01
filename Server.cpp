//
// Created by omer on 12/31/22.
//

#include "Server.h"

string file = "";
int sockNum = 0;
int size = 4096;
// This line creates a new Classification object
Classification classification;

int Server::startServer(int serverPort, string fileName) {
    file = fileName;
    const int server_port = serverPort;
    if(serverPort < 1024 || serverPort > 65535) {
        cerr << "number of port is out of bounds" << endl;
        return -1;
    }
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("error creating socket");
        return -1;
    }
    struct sockaddr_in sin;
    memset(&sin, 0, sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = INADDR_ANY;
    sin.sin_port = htons(server_port);
    if (bind(sock, (struct sockaddr *) &sin, sizeof(sin)) < 0) {
        perror("error binding socket");
        return -1;
    }
    if (listen(sock, 1) < 0) {
        perror("error listening to a socket");
        return -1;
    }
    sockNum = sock;
    while(acceptClient()) {}
    close(sock);
    return 0;
}
int Server::acceptClient() {
    struct sockaddr_in client_sin;
    unsigned int addr_len = sizeof(client_sin);
    int client_sock = accept(sockNum, (struct sockaddr *) &client_sin, &addr_len);
    if (client_sock < 0) {
        perror("error accepting client");
        return -1;
    }
    int check = 1;
    while(check) {
        string result = serverClassify(client_sock);
        if(result == "") {
            check = 0;
        }
        if(result == "close") {
            return 0;
        }
    }
}
string Server::serverClassify(int clientSock) {
    string result = "";
    char buffer[size];
    int expected_data_len = sizeof(buffer);
    int read_bytes = recv(clientSock, buffer, expected_data_len, 0);
    if (read_bytes == 0) {
        //connection is closed
        return "";
    }
    else if (read_bytes < 0) {
        // error
        return "";
    }
    else {
        //here should be the classification

        //get out of the buffer the values with integrity checks
        vector<double> vec;
        int k;
        string disType="";

        istringstream iss(buffer); // create an input string stream from the input string

        double num; // variable to store the current integer
        string str; // variable to store the string
        int count = 0; // variable to store the number of integers extracted so far
        //closing the server if the buffer have -1 and that's it
        if(buffer[0] == -1 && buffer[1] == '\0') {
            return "close";
        }
        // try to extract values from the input string until the string stream fails
        while (iss >> num) {
            ++count; // increment the count of extracted integers
        }

        // check if the number of integers is at least 2 and the string was extracted successfully
        if (count >= 1 && iss >> str >> num) {
            // the input string has the correct format, so extract the values again
            iss.clear(); // clear the string stream's fail flag
            iss.seekg(0); // reset the string stream's position to the beginning

            // extract the integers and string
            for (int i = 0; i < count - 1; ++i) {
                iss >> num;
                vec.push_back(num);
            }
            iss >> str >> num;
            disType = str;
            k = num;
            // This line calls the inputToClass function to classify the test case
            result = classification.vectorToClass(file, k, disType, vec);
            result.copy(buffer, size-1);
            //might need +1 or -1
            buffer[result.size()] = '\0';
        } else {
            // the input string does not have the correct format
            result = "invalid input";
            result.copy(buffer, size-1);
            //might need +1 or -1
            buffer[result.size()] = '\0';
        }
    }
    int sent_bytes = send(clientSock, buffer, read_bytes, 0);
    if (sent_bytes < 0) {
        perror("error sending to client");
    }
    return "good";
}