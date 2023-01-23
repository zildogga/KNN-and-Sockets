//
// Created by omer on 1/18/23.
//

#ifndef ADVANCED_PROGRAMMING_1_PROJECT_STANDARDIO_H
#define ADVANCED_PROGRAMMING_1_PROJECT_STANDARDIO_H
#include "DefaultIO.h"
#include "Data.h"

class StandardIO: public DefaultIO{
public:
    string read() override;
    void write(string) override;
    StandardIO() = default;
};


#endif //ADVANCED_PROGRAMMING_1_PROJECT_STANDARDIO_H
