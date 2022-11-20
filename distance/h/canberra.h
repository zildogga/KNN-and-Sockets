//
// Created by Omer on 20/11/2022.
//

#ifndef ADVANCED_PROGRAMMING_1_PROJECT_CANBERRA_H
#define ADVANCED_PROGRAMMING_1_PROJECT_CANBERRA_H
#include "distanceClass.h"
using namespace std;
//for from 1 to n of (abs of pi - qi) / (abs of pi + abs of qi)
class canberra:public distanceClass {

    double distance(vector<double> v1, vector<double> v2);
};


#endif //ADVANCED_PROGRAMMING_1_PROJECT_CANBERRA_H
