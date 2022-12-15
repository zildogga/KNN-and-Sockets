//
// Created by Omer on 11/12/2022.
//

#ifndef ADVANCED_PROGRAMMING_1_PROJECT_READFILE_H
#define ADVANCED_PROGRAMMING_1_PROJECT_READFILE_H
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "iostream"
using namespace std;
class ReadFile {
public:
    // this function reads a csv file by a path and returns a vector of a vector of strings
    vector<vector<string>> ReadCSVByPath(string path);
};


#endif //ADVANCED_PROGRAMMING_1_PROJECT_READFILE_H
