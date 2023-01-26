/*
 * Advanced Programming 1 Project
 * Ofir Goldberg - 315141325
 * Omer Groman - 207163452
*/

#ifndef ADVANCED_PROGRAMMING_1_PROJECT_STANDARDIO_H
#define ADVANCED_PROGRAMMING_1_PROJECT_STANDARDIO_H

#include "DefaultIO.h"
#include "Data.h"

class StandardIO : public DefaultIO {
public:
    // read function
    string read() override;
    // write function
    void write(string) override;
    // constructor
    StandardIO() = default;
};


#endif //ADVANCED_PROGRAMMING_1_PROJECT_STANDARDIO_H
