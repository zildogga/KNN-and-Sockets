//
// Created by Omer on 11/12/2022.
//

#ifndef ADVANCED_PROGRAMMING_1_PROJECT_CLASSIFICATION_H
#define ADVANCED_PROGRAMMING_1_PROJECT_CLASSIFICATION_H

#include "iostream"
#include <vector>
#include "ReadFile.h"
#include "DistanceClass.h"
#include "Knn.h"
using namespace std;
class Classification {
public:
    // gets the input and returns the class to this input
    string inputToClass(string path,int k, string disType);
    string vectorToClass(string path, int k, string disType, vector<double> test);
private:
    // gets a csv path and returns the csv file as a double and string vector
    vector<pair<vector<double>,string>> CSVToInfo (string path);
    string classify (vector<double> test, vector<pair<vector<double>,string>> information, int k, string disType);
};


#endif //ADVANCED_PROGRAMMING_1_PROJECT_CLASSIFICATION_H
