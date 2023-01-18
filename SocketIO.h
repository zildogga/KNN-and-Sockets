//
// Created by omer on 1/18/23.
//

#ifndef ADVANCED_PROGRAMMING_1_PROJECT_SOCKETIO_H
#define ADVANCED_PROGRAMMING_1_PROJECT_SOCKETIO_H
#include "DefaultIO.h"

class SocketIO: public DefaultIO{
public:
    int sock = 0;
    string read() override;
    void write(string) override;
    SocketIO(int socket);
};


#endif //ADVANCED_PROGRAMMING_1_PROJECT_SOCKETIO_H
