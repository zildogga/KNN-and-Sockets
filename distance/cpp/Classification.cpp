//
// Created by Omer on 11/12/2022.
//

#include "distance/h/Classification.h"

void Classification::inputToClass(string path,int k, string disType) {
    vector<pair<vector<double>,string>> information = CSVToInfo(path);
    DistanceClass distanceClass;
    vector<double> test;
    while (true) {
        if (!distanceClass.getVector(&test)) {
            test.clear();
            continue;
        } else {
            break;
        }
    }
    classify(test, information,k, disType);
}

vector<pair<vector<double>,string>> Classification::CSVToInfo (string path) {
    vector<pair<vector<double>,string>> information;
    ReadFile readFile;
    DistanceClass distanceClass;
    vector<vector<string>> temp = readFile.ReadCSVByPath(path);
    for (int i = 0; i < temp.size(); ++i) {
        vector<double> vTemp;
        string className=  "";
        for (int j = 0; j < temp.at(i).size(); ++j) {
            if(j!=temp.at(i).size()-1) {
                double x = distanceClass.checkValidation(temp.at(i).at(j));
                vTemp.push_back(x);
            } else {
                className = temp.at(i).at(j);
            }
        }
        pair<vector<double>,string> pairTemp(vTemp,className);
        information.push_back(pairTemp);
    }

    return information;
}

void Classification::classify (vector<double> test, vector<pair<vector<double>,string>> information, int k, string disType) {
    string chosenClass = knn(test, information, k, disType);
    cout << chosenClass << endl;
}