

#ifndef ADVANCED_PROGRAMMING_1_PROJECT_CHEBYSHEV_H
#define ADVANCED_PROGRAMMING_1_PROJECT_CHEBYSHEV_H
#include "distanceClass.h"
using namespace std;
class chebyshev:public distanceClass{
public:
    double distance(vector<double> v1, vector<double> v2) override;
};


#endif //ADVANCED_PROGRAMMING_1_PROJECT_CHEBYSHEV_H
