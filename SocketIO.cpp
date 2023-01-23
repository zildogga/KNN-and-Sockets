//
// Created by omer on 1/18/23.
//

#include "SocketIO.h"
mutex mtx;
SocketIO::SocketIO(int socket) {
    allMsg = new queue<string>();
    fiveMsg = new queue<string>();
    sock = socket;
}

string SocketIO::tryToRead() {
    //unique_lock<mutex> lock(mtx, try_to_lock);
    while (!mtx.try_lock()) {
        this_thread::sleep_for(chrono::milliseconds(100));
    }
    if (!allMsg->empty()) {
        string result = allMsg->front();
        allMsg->pop();
        //lock.unlock();
        mtx.unlock();
        return result;
    }
    mtx.unlock();
    //lock.unlock();
    return "notReady";
}


string SocketIO::read2() {
    string result;
    while ((result = tryToRead()) == "notReady") {
        this_thread::sleep_for(chrono::milliseconds(100));
        continue;
    }
    return result;
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
        return "";
    } else if (read_bytes < 0) {
        // break loop if there is an error receiving data from server
        return "";
    }
    string answer(buffer);
    return answer;
}

string SocketIO::readFive() {
    while (fiveMsg->empty()) {

    }
    string result = fiveMsg->front();
    fiveMsg->pop();
    return result;
}

void SocketIO::reciveMsg() {
    string msg = read();
    //unique_lock<mutex> lock(mtx, try_to_lock);
    while (!mtx.try_lock()) {
        this_thread::sleep_for(chrono::milliseconds(100));
    }
    if (msg.find("fiveAss") != string::npos) {
        fiveMsg->push(msg);
    } else {
        allMsg->push(msg);
    }
    mtx.unlock();
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
