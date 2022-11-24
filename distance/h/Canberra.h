

#ifndef ADVANCED_PROGRAMMING_1_PROJECT_CANBERRA_H
#define ADVANCED_PROGRAMMING_1_PROJECT_CANBERRA_H
#include "DistanceClass.h"
//for from 1 to n of (abs of pi - qi) / (abs of pi + abs of qi)
class Canberra: public DistanceClass {
public:
    double distance(vector<double> v1, vector<double> v2) override;
};


#endif //ADVANCED_PROGRAMMING_1_PROJECT_CANBERRA_H
