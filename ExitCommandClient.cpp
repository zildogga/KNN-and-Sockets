//
// Created by omer on 1/18/23.
//

#include "ExitCommandClient.h"

void ExitCommandClient::execute() {
    dio = &scio;
    dio->write("8");
    return;
}