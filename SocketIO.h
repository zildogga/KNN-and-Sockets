//
// Created by omer on 1/18/23.
//

#ifndef ADVANCED_PROGRAMMING_1_PROJECT_SOCKETIO_H
#define ADVANCED_PROGRAMMING_1_PROJECT_SOCKETIO_H
#include "DefaultIO.h"

class SocketIO: public DefaultIO{
public:
    string read() override;
    void write(string) override
};


#endif //ADVANCED_PROGRAMMING_1_PROJECT_SOCKETIO_H
