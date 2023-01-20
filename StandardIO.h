//
// Created by omer on 1/18/23.
//

#ifndef ADVANCED_PROGRAMMING_1_PROJECT_STANDARDIO_H
#define ADVANCED_PROGRAMMING_1_PROJECT_STANDARDIO_H
#include "DefaultIO.h"
#include "Data.h"

class StandardIO: public DefaultIO{
public:
    Data data;
    string read() override;
    void write(string) override;
    StandardIO(Data d);
private:
    StandardIO() = default;
};


#endif //ADVANCED_PROGRAMMING_1_PROJECT_STANDARDIO_H
