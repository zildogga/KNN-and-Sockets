

#ifndef ADVANCED_PROGRAMMING_1_PROJECT_CANBERRA_H
#define ADVANCED_PROGRAMMING_1_PROJECT_CANBERRA_H
using namespace std;
#include "distanceClass.h"
//for from 1 to n of (abs of pi - qi) / (abs of pi + abs of qi)
class canberra:public distanceClass {
public:
    double distance(vector<double> v1, vector<double> v2) override;
};


#endif //ADVANCED_PROGRAMMING_1_PROJECT_CANBERRA_H
