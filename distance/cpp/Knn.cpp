//
// Created by ofir local user on 10/12/2022.
//
#include "distance/h/Knn.h"
vector<pair<double, string>> Knn::sortDistancesVector(vector<pair<double, string>> distances) {
    pair<double, string> temp;
    for(int i = 0; i < distances.size() - 1; i++) {
        for(int j = 0; j < distances.size() - i - 1; j++) {
            if(distances[j].first > distances[j + 1].first) {
                temp = distances[j];
                distances[j] = distances[j + 1];
                distances[j + 1] = temp;
            }
        }
    }
    return distances;
}

string Knn::ClosestsNeighbers(int k, string distanceAlgo, vector<pair<vector<double>, string>> taggedVectors,
                       vector<double> inputVector) {
    vector<pair<double, string>> distances;
    if(distanceAlgo == "AUC") {
        Euclidean euc;
        for (int i = 0; i < taggedVectors.size(); i++) {
            distances.push_back(make_pair(euc.distance(taggedVectors[i].first,
                                                       inputVector), taggedVectors[i].second));
        }
    } else if(distanceAlgo == "MAN"){
        Manhattan man;
        for (int i = 0; i < taggedVectors.size(); i++) {
            distances.push_back(make_pair(man.distance(taggedVectors[i].first,
                                                       inputVector),taggedVectors[i].second));
        }
    } else if(distanceAlgo == "CHB") {
        Chebyshev chb;
        for (int i = 0; i < taggedVectors.size(); i++) {
            distances.push_back(make_pair(chb.distance(taggedVectors[i].first,
                                                       inputVector),taggedVectors[i].second));
        }
    } else if(distanceAlgo == "CAN") {
        Canberra can;
        for (int i = 0; i < taggedVectors.size(); i++) {
            distances.push_back(make_pair(can.distance(taggedVectors[i].first,
                                                       inputVector),taggedVectors[i].second));
        }
    } else if(distanceAlgo == "MIN") {
        Minkowski min;
        for (int i = 0; i < taggedVectors.size(); i++) {
            distances.push_back(make_pair(min.distance(taggedVectors[i].first,
                                                       inputVector),taggedVectors[i].second));
        }
    } else{
        cout << "Error.";
    }

    vector<pair<double, string>> sortedDistances = sortDistancesVector(distances);

    vector<string> classes;
    for(int i = 0; i < k; i++) {
        classes.push_back(sortedDistances[i].second);
    }

    int tempCount = 0;
    int maxCount = 0;
    string tempClass;
    string maxClass;
    for(int i = 0; i < classes.size(); i++) {
        for(int j = 0; j < classes.size(); j++) {
            if(classes[i] == classes[j]){
                tempCount++;
            }
        }
        if (tempCount > maxCount) {
            maxCount = tempCount;
            maxClass = classes[i];
        }
    }
    return maxClass;
}
