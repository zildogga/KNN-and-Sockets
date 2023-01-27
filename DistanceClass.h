/*
 * Advanced Programming 1 Project
 * Ofir Goldberg - 315141325
 * Omer Groman - 207163452
*/

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
    //virtual function that takes in two vector of double as parameter and return double
    virtual double distance(vector<double> v1, vector<double> v2) { return 0; };
    //function that takes in string and return double
    double checkValidation(string str);
    //function that takes in pointer to a vector of double and return bool
    bool getVector(vector<double> *v);
};



#endif //ADVANCED_PROGRAMMING_1_PROJECT_DISTANCECLASS_H
