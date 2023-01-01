//
// Created by omer on 12/31/22.
//

#include "Server.h"

string file = "";
int sockNum = 0;

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
    return 0;
}
int classify() {
    char buffer[4096];
    int expected_data_len = sizeof(buffer);
    int read_bytes = recv(client_sock, buffer, expected_data_len, 0);
    if (read_bytes == 0) {
// connection is closed
    }
    else if (read_bytes < 0) {
// error
    }
    else {
        cout << buffer;
    }
    int sent_bytes = send(client_sock, buffer, read_bytes, 0);
    if (sent_bytes < 0) {
        perror("error sending to client");
    }
}