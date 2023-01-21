//
// Created by omer on 1/18/23.
//

#include "SocketIO.h"
SocketIO::SocketIO(int socket) {
    sock = socket;
}
char *SocketIO::read() {
    char buffer[SIZE_OF_BUFFER];
    // expected length of received data
    int expected_data_len = SIZE_OF_BUFFER;
    // clear memory of buffer
    memset(buffer, 0, SIZE_OF_BUFFER);
    // try to receive data from server
    //cout << "before recv READ" << endl;
    int read_bytes = recv(sock, buffer, expected_data_len, 0);
    cout << buffer << endl;
    if (read_bytes == 0) {
        // break loop if connection is closed by server
        return "";
    } else if (read_bytes < 0) {
        // break loop if there is an error receiving data from server
        return "";
    }
    //cout << buffer << endl;
    //cout << result << endl;
    return buffer;
}

void SocketIO::write(string text) {
    char buffer[SIZE_OF_BUFFER];
    strcpy(buffer,text.c_str());
    int sent_bytes = send(sock, buffer, SIZE_OF_BUFFER, 0);
    if (sent_bytes < 0) {
        // print error message if sending data to client fails
        perror("error");
    }
}
