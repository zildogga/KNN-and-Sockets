//
// Created by omer on 1/20/23.
//

#ifndef ADVANCED_PROGRAMMING_1_PROJECT_DATA_H
#define ADVANCED_PROGRAMMING_1_PROJECT_DATA_H
#include "stdio.h"
#include "iostream"
#include "string.h"
#include "vector"

using namespace std;

class Data {
public:
    int socketNum;
    int k = 5;
    string algo = "AUC";
    vector<vector<string>> trainCSV;
    vector<vector<string>> testCSV;
    Data(int sockNum) {
       socketNum = sockNum;
    };
private:
    Data() = default;
};


#endif //ADVANCED_PROGRAMMING_1_PROJECT_DATA_H
