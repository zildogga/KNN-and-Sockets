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
        cout << "chould'nt lock in trytoread" << endl;
        this_thread::sleep_for(chrono::milliseconds(100));
    }
    cout << "start tryToRead" << endl;
    cout << "a" << endl;
    if (!allMsg->empty()) {
        cout << "c" << endl;
        string result = allMsg->front();
        cout << "d" << endl;
        allMsg->pop();
        cout << "e" << endl;
        //lock.unlock();
        mtx.unlock();
        cout << "end tryToRead 1" << endl;
        return result;
    }
    mtx.unlock();
    cout << "end tryToRead 2" << endl;
    //lock.unlock();
    return "notReady";
}


string SocketIO::read2() {
    cout << "trying read 2" << endl;
    string result;
    while ((result = tryToRead()) == "notReady") {
        cout << "read2 result : " << result << endl;
        this_thread::sleep_for(chrono::milliseconds(100));
        cout << "after sleep in read 2" << endl;
        continue;
    }
    cout << "ending read 2" << endl;
    return result;
}

string SocketIO::read() {
    cout << "trying to read" << endl;
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
    cout << "ending to read" << endl;
    return answer;
}

string SocketIO::readFive() {
    cout << "read five start" << endl;
    while (fiveMsg->empty()) {

    }
    string result = fiveMsg->front();
    fiveMsg->pop();
    cout << "read five end" << endl;
    return result;
}

void SocketIO::reciveMsg() {
    string msg = read();
    //unique_lock<mutex> lock(mtx, try_to_lock);
    while (!mtx.try_lock()) {
        cout << "chould'nt lock in recivemsg" << endl;
        this_thread::sleep_for(chrono::milliseconds(100));
    }
    cout << "start reciveMSG" << endl;
    if (msg.find("fiveAss") != string::npos) {
        fiveMsg->push(msg);
    } else {
        allMsg->push(msg);
    }
    cout << "end reciveMSG" << endl;
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
