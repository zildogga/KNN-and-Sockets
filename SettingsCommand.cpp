//
// Created by omer on 1/18/23.
//

#include "SettingsCommand.h"

void SettingsCommand::execute() {
    SocketIO socio(data->socketNum);
    dio = &socio;
    dio->write("The current KNN parameters are: K = " + to_string(data->k) + ", distance metric = " + data->algo);
    char *answer = dio->read();
    if (strcmp(answer, "\n") != 0) {
        cout << "enter something different than enter" << endl;
        // change the data
        istringstream iss(answer);
        int numTemp;
        string strTemp;
        // parse received data and store in vec
        iss >> numTemp;
        iss >> strTemp;
        if (iss.fail()) {
            cout << "invalid value for metric או invalid value for K" << endl;
            // add code for returning to menu
            ///
        } else {
            data->k = numTemp;
            data->algo = strTemp;
            dio->write("update success. \nThe current KNN parameters are: K = " + to_string(data->k)
                        + ",distance metric = "  + data->algo);
        }
        // add code for returning to menu
        ///
    } else {
        cout << "enter enter" << endl;
        // add code for returning to menu
        ///
    }
    return;
}

