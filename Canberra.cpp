#include "Canberra.h"

//for from 1 to n of (abs of pi - qi) / (abs of pi + abs of qi)
double Canberra::distance(vector<double> v1, vector<double> v2) {
    double dis = 0;
    //goes over all the values of the vector
    for (int i = 0; i < v1.size(); i++) {
        //for from 1 to n of (abs of pi - qi) / (abs of pi + abs of qi)
        dis += (abs(v1[i] - v2[i]) / ((abs(v1[i]) + abs(v2[i]))));
    }
    return dis;
}

