/*
 * Advanced Programming 1 Project
 * Ofir Goldberg - 315141325
 * Omer Groman - 207163452
*/

#include "DownloadCommandClient.h"

void DownloadCommandClient::execute() {
    //instantiate SocketIO class and pass in the socket number
    SocketIO scio(sock);
    //variable to store the string read from the server
    string serverStr;
    //set dio pointer to scio
    dio = &scio;
    //instantiate StandardIO
    StandardIO sdio;
    //vector of strings to store the server string
    vector<string> vs;
    //read from dio
    serverStr = dio->read();
    //if serverStr is "please upload data" or "please classify the data"
    if (serverStr == "please upload data" || serverStr == "please classify the data") {
        //set dio pointer to sdio
        dio = &sdio;
        //write serverStr to dio
        dio->write(serverStr);
        //return
        return;
    }
    //set dio pointer to scio
    dio = &scio;
    //while serverStr is not "Done."
    while (serverStr != "Done.") {
        //push serverStr to the vector of strings
        vs.push_back(serverStr);
        //write "ok" to dio
        dio->write("ok");
        //read from dio and store in serverStr
        serverStr = dio->read();
    }
    //create a thread that calls the ClassifyOnCommand function and pass in the vector of strings and the path, and detach the thread
    thread t(&DownloadCommandClient::ClassifyOnCommand, this, vs, path);
    t.detach();
    //return
    return;
}

void DownloadCommandClient::ClassifyOnCommand(vector<string> vs, string path) {
    //instantiate ReadFile
    ReadFile rf;
    //call WriteCSVByVector function of rf and pass in the vector of string and path
    rf.WriteCSVByVector(vs, path);
    //return
    return;
}
