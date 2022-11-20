//
// Created by Omer on 20/11/2022.
//

#ifndef ADVANCED_PROGRAMMING_1_PROJECT_MINKOWSKI_H
#define ADVANCED_PROGRAMMING_1_PROJECT_MINKOWSKI_H
#include <vector>
#include <cmath>
using namespace std;
//d(x,y) = (for from 1 to n of abs of (xi - yi)^p)^(1/p)

class minkowski {
public:
    double distance(std::vector<double>v1,std::vector<double>v2);
};


#endif //ADVANCED_PROGRAMMING_1_PROJECT_MINKOWSKI_H
