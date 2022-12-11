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
    void inputToClass(string path,int k, string disType);
private:
    vector<pair<vector<double>,string>> CSVToInfo (string path);
    void classify (vector<double> test, vector<pair<vector<double>,string>> information, int k, string disType);
};


#endif //ADVANCED_PROGRAMMING_1_PROJECT_CLASSIFICATION_H
