
#ifndef ADVANCED_PROGRAMMING_1_PROJECT_EUCLIDEAN_H
#define ADVANCED_PROGRAMMING_1_PROJECT_EUCLIDEAN_H
#include "distanceClass.h"
class euclidean:public distanceClass{
public:
    double distance(vector<double> v1, vector<double> v2) override;
};


#endif //ADVANCED_PROGRAMMING_1_PROJECT_EUCLIDEAN_H
