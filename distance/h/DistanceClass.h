

#ifndef ADVANCED_PROGRAMMING_1_PROJECT_DISTANCECLASS_H
#define ADVANCED_PROGRAMMING_1_PROJECT_DISTANCECLASS_H
#include "iostream"
#include <vector>
#include <cmath>
#include "float.h"
#include "string"
using namespace std;

class DistanceClass {
public:
    virtual double distance(std::vector<double> v1, std::vector<double> v2){return 0;};
    double checkValidation(string str);
    bool getVector(vector<double> *v);
};


#endif //ADVANCED_PROGRAMMING_1_PROJECT_DISTANCECLASS_H
