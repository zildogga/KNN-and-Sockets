/*
 * Advanced Programming 1 Project
 * Ofir Goldberg - 315141325
 * Omer Groman - 207163452
*/

#include "SettingsCommandServer.h"

void SettingsCommandServer::execute() {
    // Create a SocketIO object for the current socket number
    SocketIO socio(data->socketNum);
    // set the data io to the newly created SocketIO object
    dio = &socio;
    // write the current parameters to the client
    dio->write("The current KNN parameters are: K = " + to_string(data->k) + ", distance metric = " + data->algo);
    // read the client's response
    string answer = "";
    answer = dio->read();
    if (!answer.empty()) {
        // create a stream to parse the client's response
        istringstream iss(answer);
        int numTemp;
        string strTemp;
        bool strFlag = false, numFlag = false;
        if (iss >> numTemp) {
            // check if the first token is a number
            numFlag = true;
        }
        // reset the stream
        iss.clear();
        iss.seekg(0);
        if (iss >> strTemp) {
            if (iss >> strTemp) {
                // check if the second token is a valid distance metric
                if (strTemp == "AUC" || strTemp == "MIN" || strTemp == "MAN" || strTemp == "CHB" || strTemp == "CAN") {
                    if (numFlag == true) {
                        // check if the number is valid
                        if(numTemp <= 0) {
                            // printing wrong k for user
                            dio->write("invalid value for K");
                            return;
                        }
                        // update the data
                        data->k = numTemp;
                        data->algo = strTemp;
                        // inform the client of the update
                        dio->write("update success. \nThe current KNN parameters are: K = " + to_string(data->k)
                                   + ",distance metric = " + data->algo);
                    }
                    strFlag = true;
                }
            }
        }
        if (numFlag == false && strFlag == false) {
            // if neither token is valid
            dio->write("invalid value for metric\ninvalid value for K");
        } else if (numFlag == false) {
            // if the number is invalid
            dio->write("invalid value for K");
        } else if (strFlag == false) {
            // if the metric is invalid
            dio->write("invalid value for metric");
        }
    } else {
            // user was not trying to change k or metric
            dio->write("User pressed enter");
    }
    // exit function
    return;
}

