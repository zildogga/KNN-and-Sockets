//
// Created by ofir local user on 10/12/2022.
//
#include "Knn.h"
// This function is part of the Knn class
vector<pair<double, string>> Knn::sortDistancesVector(
        // This function takes a vector of pairs of doubles and strings as input
        vector<pair<double, string>> distances
) {
    // This line creates a new empty pair of a double and a string
    pair<double, string> temp;
    // This loop iterates over the elements in the vector of pairs, except for the last element
    for(int i = 0; i < distances.size() - 1; i++) {
        // This inner loop iterates over the elements in the vector of pairs, from the first element to the element at the current
        // position of the outer loop
        for(int j = 0; j < distances.size() - i - 1; j++) {
            // This line compares the first element (i.e. the distance) in the current pair to the first element in the next pair.
            // If the current distance is greater than the next distance, the pairs are swapped
            if(distances[j].first > distances[j + 1].first) {
                temp = distances[j];
                distances[j] = distances[j + 1];
                distances[j + 1] = temp;
            }
        }
    }
    // This line returns the vector of pairs, now sorted in ascending order by distance
    return distances;
}


// This function is part of the Knn class
string Knn::ClosestsNeighbers(
        // This function takes an integer k as input, representing the number of nearest neighbors to consider
        int k,
        // This function takes a string representing the distance algorithm to use as input
        string distanceAlgo,
        // This function takes a vector of pairs of vectors of doubles and strings representing the training data as input
        vector<pair<vector<double>, string>> taggedVectors,
        // This function takes a vector of doubles representing the test case as input
        vector<double> inputVector
) {
    // This line creates a new empty vector of pairs of doubles and strings
    vector<pair<double, string>> distances;
    // If the distance algorithm is "AUC", this block calculates the distances using the Euclidean distance
    // and adds the distances and corresponding class names to the vector of pairs
    if(distanceAlgo == "AUC") {
        // This line creates a new Euclidean object
        Euclidean euc;
        // This loop iterates over the training data
        for (int i = 0; i < taggedVectors.size(); i++) {
            // This line calculates the Euclidean distance between the current training example and the test case,
            // and adds the distance and corresponding class name to the vector of pairs
            distances.push_back(make_pair(euc.distance(taggedVectors[i].first, inputVector), taggedVectors[i].second));
        }
        // If the distance algorithm is "MAN", this block calculates the distances using the Manhattan distance
        // and adds the distances and corresponding class names to the vector of pairs
    } else if(distanceAlgo == "MAN"){
        // This line creates a new Manhattan object
        Manhattan man;
        // This loop iterates over the training data
        for (int i = 0; i < taggedVectors.size(); i++) {
            // This line calculates the Manhattan distance between the current training example and the test case,
            // and adds the distance and corresponding class name to the vector of pairs
            distances.push_back(make_pair(man.distance(taggedVectors[i].first, inputVector), taggedVectors[i].second));
        }
        // If the distance algorithm is "CHB", this block calculates the distances using the Chebyshev distance and adds
        // the distances and corresponding class names to the vector of pairs
    } else if(distanceAlgo == "CHB") {
        // This line creates a new Chebyshev object
        Chebyshev chb;
        // This loop iterates over the training data
        for (int i = 0; i < taggedVectors.size(); i++) {
            // This line calculates the Chebyshev distance between the current training example and the test case,
            // and adds the distance and corresponding class name to the vector of pairs
            distances.push_back(make_pair(chb.distance(taggedVectors[i].first, inputVector), taggedVectors[i].second));
        }
        // If the distance algorithm is "CAN", this block calculates the distances using the Canberra distance
        // and adds the distances and corresponding class names to the vector of pairs
    } else if(distanceAlgo == "CAN") {
        // This line creates a new Canberra object
        Canberra can;
        // This loop iterates over the training data
        for (int i = 0; i < taggedVectors.size(); i++) {
            // This line calculates the Canberra distance between the current training example and the test case,
            // and adds the distance and corresponding class name to the vector of pairs
            distances.push_back(make_pair(can.distance(taggedVectors[i].first, inputVector), taggedVectors[i].second));
        }
        // If the distance algorithm is "MIN", this block calculates the distances using the Minkowski distance
        // and adds the distances and corresponding class names to the vector of pairs
    } else if(distanceAlgo == "MIN") {
        // This line creates a new Minkowski object
        Minkowski min;
        // This loop iterates over the training data
        for (int i = 0; i < taggedVectors.size(); i++) {
            // This line calculates the Minkowski distance between the current training example and the test case,
            // and adds the distance and corresponding class name to the vector of pairs
            distances.push_back(make_pair(min.distance(taggedVectors[i].first, inputVector), taggedVectors[i].second));
        }
        // If the distance algorithm is not one of the above, this block prints an error message
    } else{
        return "Error";
    }

    // This line calls the sortDistancesVector function to sort the vector of pairs of distances and class names in ascending order by distance
    vector<pair<double, string>> sortedDistances = sortDistancesVector(distances);

    // This line creates a new empty vector of strings to store the classes of the k nearest neighbors
    vector<string> classes;
    // This loop iterates over the k nearest neighbors and adds their class names to the vector of classes
    for(int i = 0; i < k; i++) {
        classes.push_back(sortedDistances[i].second);
    }

    // This line initializes a variable to store the number of occurrences of the current class in the vector of classes
    int tempCount = 0;
    // This line initializes a variable to store the maximum number of occurrences of any class in the vector of classes
    int maxCount = 0;
    // This line initializes a variable to store the current class
    string tempClass;
    // This line initializes a variable to store the class with the most occurrences in the vector of classes
    string maxClass;
    // This outer loop iterates over the classes in the vector of classes
    for(int i = 0; i < classes.size(); i++) {
        // Resets the tempCount
        tempCount = 0;
        // This inner loop iterates over the classes in the vector of classes
        for(int j = 0; j < classes.size(); j++) {
            // If the current class in the outer loop is the same as the current class in the inner loop, the count of occurrences is incremented
            if(classes[i] == classes[j]){
                tempCount++;
            }
        }
        // If the current count of occurrences is greater than the maximum number of occurrences,
        // the maximum count and the class with the most occurrences are updated
        if (tempCount > maxCount) {
            maxCount = tempCount;
            maxClass = classes[i];
        }
    }
    // This line returns the class with the most occurrences in the vector of classes
    return maxClass;
}
