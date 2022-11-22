

#ifndef ADVANCED_PROGRAMMING_1_PROJECT_DISTANCECLASS_H
#define ADVANCED_PROGRAMMING_1_PROJECT_DISTANCECLASS_H
#include "iostream"
#include <vector>
#include <cmath>
using namespace std;

class distanceClass {
    public:
        virtual double distance(std::vector<double> v1, std::vector<double> v2){};
        double checkValidation(string str);
};


#endif //ADVANCED_PROGRAMMING_1_PROJECT_DISTANCECLASS_H
