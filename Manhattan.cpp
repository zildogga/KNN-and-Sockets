/*
 * Advanced Programming 1 Project
 * Ofir Goldberg - 315141325
 * Omer Groman - 207163452
*/

#include "Manhattan.h"

// Calculate the Manhattan distance of 2 vectors. d(v1,v2) = sigma of the absolute value of v1[i] - v2[i] when i run
// form 0 to v1/v2.size
double Manhattan::distance(std::vector<double> v1, std::vector<double> v2) {
    // initialize distance to 0
    double distance = 0;
    // iterate through elements in v1
    for (int i = 0; i < v1.size(); i++) {
        // add absolute value of difference between corresponding elements in v1 and v2 to distance
        distance += abs(v1[i] - v2[i]);
    }
    // return distance
    return distance;
}
