//
// Created by omer on 1/18/23.
//

#include "SettingsCommand.h"

void SettingsCommand::execute() {
    Data d;
    StandardIO stio(d);
    dio = &stio;
    dio->write("The current KNN parameters are: K = "+to_string(stio.data.k)+", distance metric = "+stio.data.algo);
}
