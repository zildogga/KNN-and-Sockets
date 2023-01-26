/*
 * Advanced Programming 1 Project
 * Ofir Goldberg - 315141325
 * Omer Groman - 207163452
*/

#include "DownloadCommandServer.h"

void DownloadCommandServer::execute() {
    //variable to store the data
    string temp;
    //create a SocketIO object
    SocketIO socio(data->socketNum);
    //set dio to the SocketIO object
    dio = &socio;
    //check if trainCSV or testCSV is empty
    if (data->trainCSV.empty() || data->testCSV.empty()) {
        //if so, write "please upload data" to dio
        dio->write("please upload data");
        //return
        return;
    }
    //check if classified is empty
    if (data->classified.empty()) {
        //if so, write "please classify the data" to dio
        dio->write("please classify the data");
        //return
        return;
    }
    //loop through the classified data
    for (int i = 0; i < data->classified.size(); i++) {
        //store the index and the classified data in temp
        temp = to_string(i + 1) + ',' + data->classified.at(i);
        //write temp to dio
        dio->write(temp);
        //read from dio
        dio->read();
    }
    //write "Done." to dio
    dio->write("Done.");
    //return
    return;
}
