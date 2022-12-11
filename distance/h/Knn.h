//
// Created by ofir local user on 10/12/2022.
//

#ifndef ADVANCED_PROGRAMMING_1_PROJECT_KNN_H
#define ADVANCED_PROGRAMMING_1_PROJECT_KNN_H
#include "string"
#include "vector"
#include "iostream"
#include "distance/h/DistanceClass.h"
#include "distance/h/Euclidean.h"
#include "distance/h/Canberra.h"
#include "distance/h/Chebyshev.h"
#include "distance/h/Manhattan.h"
#include "distance/h/Minkowski.h"

using namespace std;
class Knn {
public:
    void ClosestsNeighbers(int k, string distanceAlgo, vector<vector<double>> taggedVectors,
                           vector<double> inputVector, vector<string> types);
};





#endif //ADVANCED_PROGRAMMING_1_PROJECT_KNN_H
