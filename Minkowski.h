/*
 * Advanced Programming 1 Project
 * Ofir Goldberg - 315141325
 * Omer Groman - 207163452
*/

#ifndef ADVANCED_PROGRAMMING_1_PROJECT_MINKOWSKI_H
#define ADVANCED_PROGRAMMING_1_PROJECT_MINKOWSKI_H

#include "DistanceClass.h"

//the p from the algorithm
const double p = 2;
//d(x,y) = (for from 1 to n of abs of (xi - yi)^p)^(1/p)

class Minkowski : public DistanceClass {
public:
    double distance(vector<double> v1, vector<double> v2) override;
};


#endif //ADVANCED_PROGRAMMING_1_PROJECT_MINKOWSKI_H
