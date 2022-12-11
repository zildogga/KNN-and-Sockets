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
    vector<vector<string>> ReadCSVByPath(string path);
};


#endif //ADVANCED_PROGRAMMING_1_PROJECT_READFILE_H
