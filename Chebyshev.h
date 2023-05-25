/*
 * Advanced Programming 1 Project
 * Ofir Goldberg - 315141325
 * Omer Groman - 207163452
*/

#ifndef ADVANCED_PROGRAMMING_1_PROJECT_CHEBYSHEV_H
#define ADVANCED_PROGRAMMING_1_PROJECT_CHEBYSHEV_H

#include "DistanceClass.h"

class Chebyshev : public DistanceClass {
public:
    double distance(vector<double> v1, vector<double> v2) override;
};


#endif //ADVANCED_PROGRAMMING_1_PROJECT_CHEBYSHEV_H
