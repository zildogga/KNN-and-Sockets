/*
 * Advanced Programming 1 Project
 * Ofir Goldberg - 315141325
 * Omer Groman - 207163452
*/

#include "ClassifyCommandServer.h"

void ClassifyCommandServer::execute() {
    // Declare an object of SocketIO class, which takes in the socket number
    SocketIO scio(data->socketNum);
    // Point the dio pointer to the scio object
    dio = &scio;
    // Check if the trainCSV and testCSV attributes of the data object are empty
    if (data->trainCSV.empty() || data->testCSV.empty()) {
        // If true, write "please upload data" to the connected socket
        dio->write("please upload data");
    } else {
        // Declare an object of Classification class
        Classification cl;
        // Iterate through the testCSV attribute of the data object
        for (int i = 0; i < data->testCSV.size(); i++) {
            // Classify the test data by the train data, and store the result in the classified attribute of the data object
            data->classified[i] = cl.classifyTestByTrain(data->testCSV.at(i), data->trainCSV, data->k, data->algo);
            // Check if the classified result is "input was not a number"
            if (data->classified[i] == "input was not a number") {
                // If true, write "input was not a number" to the connected socket
                dio->write("input was not a number");
                // Clear the classified attribute
                data->classified.clear();
                // Exit the function
                return;
            }
        }
        // After the classification, write "classifying data complete" to the connected socket
        dio->write("classifying data complete");
    }
    // Exit the function
    return;
}
