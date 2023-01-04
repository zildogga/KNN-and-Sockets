//
// Created by omer on 12/31/22.
//

#include "Server.h"

string file = "";
int sockNum = 0;
int size = 4096;
// This line creates a new Classification object
Classification classification;
ReadFile readFile;

int Server::startServer(string serverPort, string fileName) {
    int port;
    istringstream iss(serverPort);
    if (iss >> port) {
    } else {
        cerr << "invalid input" << endl;
        return 0;
    }
    file = fileName;
    vector<vector<string>> readFileTry = readFile.ReadCSVByPath(fileName);
    if(readFileTry.empty()) {
        return -1;
    }
    const int server_port = port;
    if(server_port < 1024 || server_port > 65535) {
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
    while(acceptClient()) {
        cout << "waiting for a new client" << endl;
    }
    close(sock);
    return 0;
}
int Server::acceptClient() {
    struct sockaddr_in client_sin;
    unsigned int addr_len = sizeof(client_sin);
    int client_sock = accept(sockNum, (struct sockaddr *) &client_sin, &addr_len);
    if (client_sock < 0) {
        perror("error accepting client");
        return 1;
    }
    while(true) {
        string result = serverClassify(client_sock);
        if(result == "") {
            return 1;
        }
    }
}
string Server::serverClassify(int clientSock) {
    string result = "";
    char buffer[size];
    int expected_data_len = sizeof(buffer);
    memset(buffer, 0, sizeof(buffer));
    cout << "waiting for receive by client" << endl;
    int read_bytes = recv(clientSock, buffer, expected_data_len, 0);
    cout << "the buffer is: " << buffer << endl;
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
        string disType="o";

        istringstream iss(buffer); // create an input string stream from the input string

        //closing the server if the buffer have -1 and that's it
        cout << "checking for buffer to be -1" << endl;
        if(buffer[0] == '-' && buffer[1] == '1' && buffer[2] == '\0') {
            cout << "buffer is indeed -1" << endl;
            result = "close";
            strcpy(buffer,result.c_str());
            int sent_bytes = send(clientSock, buffer, result.size(), 0);
            if (sent_bytes < 0) {
                perror("error sending to client");
            }
            cout << "returning close client to the while" << endl;
            return "closeClient";
        }
        double num;
        int count = 0;
        // try to extract values from the input string until the string stream fails
        while (iss >> num) {
            count++;
            vec.push_back(num);
        }
        // the input string has the correct format, so extract the values again
        iss.clear(); // clear the string stream's fail flag
        iss.seekg(0); // reset the string stream's position to the beginning
        for (int i = 0; i < count+2; i++) {
            if(i<count) {
                iss >> num;
            } else if(i==count) {
                iss >> disType;
            } else {
                iss >> k;
            }
        }
        cout << iss.str() << endl;
        if (iss.fail()) {
            // the input string does not have the correct format
            result = "invalid input";
            //result.copy(buffer, size-1);
            strcpy(buffer,result.c_str());
            //might need +1 or -1
            //buffer[result.size()] = '\0';
        } else {
            // This line calls the inputToClass function to classify the test case
            result = classification.vectorToClass(file, k, disType, vec);
            //result.copy(buffer, size - 1);
            //might need +1 or -1
            //buffer[result.size()] = '\0';
            strcpy(buffer,result.c_str());
        }
    }
    cout << "sending this to client: " << buffer << endl;
    int sent_bytes = send(clientSock, buffer, result.size(), 0);
    if (sent_bytes < 0) {
        perror("error sending to client");
    }
    return "good";
}