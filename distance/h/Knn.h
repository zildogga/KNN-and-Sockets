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
    string ClosestsNeighbers(int k, string distanceAlgo, vector<pair<vector<double>, string>> taggedVectors,
                             vector<double> inputVector);
    vector<pair<double, string>> sortDistancesVector(vector<pair<double, string>> distances);
};





#endif //ADVANCED_PROGRAMMING_1_PROJECT_KNN_H
