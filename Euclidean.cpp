/*
 * Advanced Programming 1 Project
 * Ofir Goldberg - 315141325
 * Omer Groman - 207163452
*/

#include "Euclidean.h"

// calculate the Euclidean distance of 2 vectors. d(p,q) = square root of sigma (v1[i] - v2[i]) ^ 2
// when i run form 0 to v1/v2.size
double Euclidean::distance(std::vector<double> v1, std::vector<double> v2) {
    double tempDistance = 0;
    double distance;
    // calculate the sigma of (v1[i] - v2[i]) ^ 2
    for (int i = 0; i < v1.size(); i++) {
        tempDistance += pow((v1[i] - v2[i]), 2);
    }
    // square root to the sigma
    distance = sqrt(tempDistance);
    return distance;
}