/*
 * Advanced Programming 1 Project
 * Ofir Goldberg - 315141325
 * Omer Groman - 207163452
*/

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
    // takes a file path, an integer k, and a string disType as input and returns a string
    string inputToClass(string path, int k, string disType);
    // takes a file path, an integer k, a string disType, and a vector of doubles as input and returns a string
    string vectorToClass(string path, int k, string disType, vector<double> test);
    // takes a vector of strings, a vector of vector of strings, an integer k, and a string disType as input and returns a string
    string classifyTestByTrain(vector<string> testVector, vector<vector<string>> trainCSV, int k, string disType);
private:
    // takes a file path as input and returns a vector of pairs of vectors of doubles and strings
    vector<pair<vector<double>, string>> CSVToInfo(string path);
    // takes a vector of doubles, a vector of pairs of vectors of doubles and strings, an integer k and a string disType as input and returns a string
    string classify(vector<double> test, vector<pair<vector<double>, string>> information, int k, string disType);
};



#endif //ADVANCED_PROGRAMMING_1_PROJECT_CLASSIFICATION_H
