/*
 * Advanced Programming 1 Project
 * Ofir Goldberg - 315141325
 * Omer Groman - 207163452
*/

#ifndef ADVANCED_PROGRAMMING_1_PROJECT_DATA_H
#define ADVANCED_PROGRAMMING_1_PROJECT_DATA_H

#include "stdio.h"
#include "iostream"
#include "string.h"
#include "vector"
#include "map"
#define DEFAULT_K 5
#define DEFAULT_ALGO "AUC"
using namespace std;

class Data {
public:
    // Declare the socket number
    int socketNum;
    // Declare k with default value of 5
    int k = DEFAULT_K;
    // Declare algo with default value of "AUC"
    string algo = DEFAULT_ALGO;
    // Declare trainCSV as vector, of vector, of strings
    vector<vector<string>> trainCSV;
    // Declare testCSV as vector, of vector, of strings
    vector<vector<string>> testCSV;
    // Declare classified as map of int and string
    map<int, string> classified;

    // constructor that takes socket number as input
    Data(int sockNum) {
        socketNum = sockNum;
    };

    // constructor that takes all inputs as input
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
    // default constructor
    Data() = default;
};


#endif //ADVANCED_PROGRAMMING_1_PROJECT_DATA_H
