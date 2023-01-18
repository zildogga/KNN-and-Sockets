//
// Created by omer on 1/18/23.
//

#include "UploadCommand.h"

void UploadCommand::execute() {
    StandardIO std;
    dio = &std;
    string text = dio->read();
    cout << text << endl;
}
