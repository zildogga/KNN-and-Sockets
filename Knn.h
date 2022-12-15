//
// Created by ofir local user on 10/12/2022.
//

#ifndef ADVANCED_PROGRAMMING_1_PROJECT_KNN_H
#define ADVANCED_PROGRAMMING_1_PROJECT_KNN_H
#include "string"
#include "vector"
#include "iostream"
#include "DistanceClass.h"
#include "Euclidean.h"
#include "Canberra.h"
#include "Chebyshev.h"
#include "Manhattan.h"
#include "Minkowski.h"

using namespace std;
class Knn {
public:
    string ClosestsNeighbers(int k, string distanceAlgo, vector<pair<vector<double>, string>> taggedVectors,
                             vector<double> inputVector);
    vector<pair<double, string>> sortDistancesVector(vector<pair<double, string>> distances);
};





#endif //ADVANCED_PROGRAMMING_1_PROJECT_KNN_H
