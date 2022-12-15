
//d(x,y) = (for from 1 to n of abs of (xi - yi)^p)^(1/p)
#include "Minkowski.h"

double Minkowski::distance(vector<double> v1, vector<double> v2) {
    double dis = 0;
    //goes over all the arguments on the vector
    for (int i = 0; i < v1.size(); i++) {
        //absolute value of xi-yi, and to the power of p
        dis += pow(abs(v1[i] - v2[i]), p);
    }
    //lastly returning the distance to the power of 1/p
    return pow(dis, (1 / p));
}
