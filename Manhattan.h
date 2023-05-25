/*
 * Advanced Programming 1 Project
 * Ofir Goldberg - 315141325
 * Omer Groman - 207163452
*/

#ifndef ADVANCED_PROGRAMMING_1_PROJECT_MANHATTAN_H
#define ADVANCED_PROGRAMMING_1_PROJECT_MANHATTAN_H

#include "DistanceClass.h"

class Manhattan : public DistanceClass {
public:
    // function to calculate distance between two vectors using Manhattan distance
    double distance(vector<double> v1, vector<double> v2) override;
};


#endif //ADVANCED_PROGRAMMING_1_PROJECT_MANHATTAN_H
