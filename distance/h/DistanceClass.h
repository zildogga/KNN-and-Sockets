

#ifndef ADVANCED_PROGRAMMING_1_PROJECT_DISTANCECLASS_H
#define ADVANCED_PROGRAMMING_1_PROJECT_DISTANCECLASS_H
#include "iostream"
#include <vector>
#include <cmath>
#include "float.h"
using namespace std;

class DistanceClass {
    public:
        virtual double distance(std::vector<double> v1, std::vector<double> v2){};
        double checkValidation(string str);
};


#endif //ADVANCED_PROGRAMMING_1_PROJECT_DISTANCECLASS_H
