/*
 * Advanced Programming 1 Project
 * Ofir Goldberg - 315141325
 * Omer Groman - 207163452
*/

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
    // this function returns the class of the closest Neighbors by the k, algorithm and the vector to check
    string ClosestsNeighbers(int k, string distanceAlgo, vector<pair<vector<double>, string>> taggedVectors,
                             vector<double> inputVector);
    // this function sorts the vectors by distances as asc
    vector<pair<double, string>> sortDistancesVector(vector<pair<double, string>> distances);
};


#endif //ADVANCED_PROGRAMMING_1_PROJECT_KNN_H
