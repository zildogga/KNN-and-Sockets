//
// Created by Omer on 20/11/2022.
//

#include "chebyshev.h"

double chebyshev::distance(std::vector<double> v1, std::vector<double> v2) {
    double dis = 0;
    //goes over all the values
    for (int i = 0; i < v1.size(); ++i) {
        //goes over all the pairs by current value
        double current = abs(v1[i] - v2[i]);
        //if the current value is bigger the distance should be changed
        if (current > dis) {
            dis = current;
        }
    }
    //returns the maximum distance between the pairs
    return dis;
}