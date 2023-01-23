//
// Created by omer on 1/20/23.
//

#ifndef ADVANCED_PROGRAMMING_1_PROJECT_DATA_H
#define ADVANCED_PROGRAMMING_1_PROJECT_DATA_H

#include "stdio.h"
#include "iostream"
#include "string.h"
#include "vector"
#include "map"

using namespace std;

class Data {
public:
    int socketNum;
    int k = 5;
    string algo = "AUC";
    vector<vector<string>> trainCSV;
    vector<vector<string>> testCSV;
    map<int, string> classified;

    Data(int sockNum) {
        socketNum = sockNum;
    };

    Data(int socketNum1, int k1, string algo1, vector<vector<string>> trainCSV1, vector<vector<string>> testCSV1,
         map<int, string> classified1) {
        socketNum = socketNum1;
        k = k1;
        algo = algo1;
        trainCSV = trainCSV1;
        testCSV = testCSV1;
        classified = classified1;
    };

private:
    Data() = default;
};


#endif //ADVANCED_PROGRAMMING_1_PROJECT_DATA_H
