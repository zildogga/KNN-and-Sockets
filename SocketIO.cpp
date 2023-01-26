//
// Created by omer on 1/18/23.
//

#include "SocketIO.h"
//mutex mtx;
SocketIO::SocketIO(int socket) {
    sock = socket;
}

string SocketIO::read() {
    char buffer[SIZE_OF_BUFFER];
    // expected length of received data
    int expected_data_len = SIZE_OF_BUFFER;
    // clear memory of buffer
    memset(buffer, 0, SIZE_OF_BUFFER);
    // try to receive data from server
    int read_bytes = recv(sock, buffer, expected_data_len, 0);
    if (read_bytes == 0) {
        // break loop if connection is closed by server
        close(sock);
        return "close";
    } else if (read_bytes < 0) {
        close(sock);
        // break loop if there is an error receiving data from server
        return "close";
    }
    string answer(buffer);
    return answer;
}

void SocketIO::write(string text) {
    char buffer[SIZE_OF_BUFFER];
    strcpy(buffer, text.c_str());
    int sent_bytes = send(sock, buffer, SIZE_OF_BUFFER, 0);
    if (sent_bytes < 0) {
        // print error message if sending data to client fails
        perror("error");
    }
}
