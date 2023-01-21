//
// Created by omer on 1/18/23.
//

#include "SettingsCommandServer.h"

void SettingsCommandServer::execute() {
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
        bool strFlag = false, numFlag = false;
        if (iss >> numTemp) {
            numFlag = true;
        }
        iss.clear();
        iss.seekg(0);
        if (iss >> strTemp) {
            if (iss >> strTemp) {
                if (strTemp == "AUC" || strTemp == "MIN" || strTemp == "MAN" || strTemp == "CHB" || strTemp == "CAN") {
                    if (numFlag == true) {
                        data->k = numTemp;
                        data->algo = strTemp;
                        dio->write("update success. \nThe current KNN parameters are: K = " + to_string(data->k)
                                   + ",distance metric = " + data->algo);
                    }
                    strFlag = true;
                }
            }
        }
        if (numFlag == false && strFlag == false) {
            dio->write("invalid value for metric\ninvalid value for K");
        } else if (numFlag == false) {
            dio->write("invalid value for K");
        } else if (strFlag == false) {
            dio->write("invalid value for metric");
        }
    }
    cout << "k = " << data->k << " algo = " << data->algo << endl;
    return;
}

