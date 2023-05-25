/*
 * Advanced Programming 1 Project
 * Ofir Goldberg - 315141325
 * Omer Groman - 207163452
*/

#include "DisplayCommandServer.h"

void DisplayCommandServer::execute() {
    //instantiate SocketIO class and pass in the socket number from the data
    SocketIO socio(data->socketNum);
    //set dio pointer to socio
    dio = &socio;
    //variable to store temporary string
    string temp;
    //if data->trainCSV or data->testCSV is empty
    if (data->trainCSV.empty() || data->testCSV.empty()) {
        //write "please upload data" to dio
        dio->write("please upload data");
        //return
        return;
    }
    //if data->classified is empty
    if (data->classified.empty()) {
        //write "please classify the data" to dio
        dio->write("please classify the data");
        //return
        return;
    }
    //iterate over data->classified
    for (int i = 0; i < data->classified.size(); i++) {
        //create a string with the index and the value from data->classified
        temp = to_string(i + 1) + " " + data->classified[i];
        //write the temp string to dio
        dio->write(temp);
        //read from dio
        dio->read();
        //sleep for 100 milliseconds
        this_thread::sleep_for(chrono::milliseconds(100));
    }
    //write "Done." to dio
    dio->write("Done.");
    //return
    return;
}
