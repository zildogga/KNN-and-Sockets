/*
 * Advanced Programming 1 Project
 * Ofir Goldberg - 315141325
 * Omer Groman - 207163452
*/

#include "UploadCommandServer.h"

void UploadCommandServer::execute() {
    //Creating a SocketIO object with a given socket number
    SocketIO socketIO(data->socketNum);
    //Assigning the address of the object to the dio pointer
    dio = &socketIO;
    //Sending a message to the client to upload the train CSV file
    dio->write("Please upload your local train CSV file.");
    //initializing a variable to hold the current line of the CSV file
    string currentLine1;
    //initializing a list to hold the lines of the CSV file
    list<string> trainCSVList;
    //reading the lines of the CSV file
    while ((currentLine1 = dio->read()) != "endOfFile") {
        //sending a message to the client to confirm receipt of the line
        dio->write("ok");
        //adding the line to the list
        trainCSVList.push_back(currentLine1);
    }
    //Checking if the list is empty
    if (trainCSVList.empty()) {
        dio->write("invalid input");
        //Return if empty
        return;
    }
    //initializing a 2D vector to hold the lines of the CSV file
    vector<vector<string>> trainCSVVector;
    //Creating an object of the ReadFile class
    ReadFile rf1;
    //Converting the list to a 2D vector
    trainCSVVector = rf1.ReadCSVByList(trainCSVList);
    data->trainCSV = trainCSVVector;
    // print to user
    dio->write("Upload complete."
               "\nPlease upload your local test CSV file.");

    // second upload
    //declaring a string variable to hold the current line read from the test csv file
    string currentLine2;
    // a list to hold all lines read from the test csv file
    list<string> testCSVList;
    // keep reading lines from the test csv file until "endOfFile" is encountered
    while ((currentLine2 = dio->read()) != "endOfFile") {
        // send "ok" to the client as a confirmation that the line was received
        dio->write("ok");
        // add the current line to the list of lines
        testCSVList.push_back(currentLine2);
    }
    // if the list is empty, it means no valid input was received
    if (testCSVList.empty()) {
        dio->write("invalid input");
        return;
    }
    // declare a 2D vector to hold the test csv data
    vector<vector<string>> testCSVVector;
    // create an object of the ReadFile class
    ReadFile rf2;
    // use the ReadCSVByList method to convert the list of lines to a 2D vector
    testCSVVector = rf2.ReadCSVByList(testCSVList);
    // update the data object's testCSV member variable with the newly read test csv data
    data->testCSV = testCSVVector;
    // send "Upload complete." to the client to indicate that the upload process is finished
    dio->write("Upload complete.");
}
