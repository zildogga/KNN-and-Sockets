/*
 * Advanced Programming 1 Project
 * Ofir Goldberg - 315141325
 * Omer Groman - 207163452
*/

#ifndef ADVANCED_PROGRAMMING_1_PROJECT_READFILE_H
#define ADVANCED_PROGRAMMING_1_PROJECT_READFILE_H

#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "iostream"
#include "list"

using namespace std;

class ReadFile {
public:
    // this function reads a csv file by a path and returns a vector of a vector of strings
    vector<vector<string>> ReadCSVByPath(string path);
    // this function reads a csv file by a list and returns a vector of a vector of strings
    vector<vector<string>> ReadCSVByList(list<string> list);
    // this function write CSV vector by vector
    void WriteCSVByVector(vector<string> information, string path);
};

#endif //ADVANCED_PROGRAMMING_1_PROJECT_READFILE_H
