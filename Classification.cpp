#include "Classification.h"

// This function is part of the Classification class
string Classification::vectorToClass(
        // This function takes a path to a CSV file as input
        string path,
        // This function takes an integer k as input
        int k,
        // This function takes a string representing a distance type as input
        string disType,
        vector<double> test
) {
    // This line converts the CSV file at the given path to a vector of pairs of vectors of doubles and strings
    vector<pair<vector<double>, string>> information = CSVToInfo(path);
    // This line creates a new DistanceClass object
    DistanceClass distanceClass;
    // If the user entered a vector of doubles, this line checks if the vector has the correct size
    if (test.size() != information[0].first.size()) {
        // This line sends an error message to the standard error stream
        return "invalid input";
        // This line continues the loop, prompting the user to enter a valid vector of doubles again
    }
    // CSV file, the value of k, and the distance type
    string result = classify(test, information, k, disType);
    return result;
}

// This function is part of the Classification class
string Classification::inputToClass(
        // This function takes a path to a CSV file as input
        string path,
        // This function takes an integer k as input
        int k,
        // This function takes a string representing a distance type as input
        string disType
) {
    // This line converts the CSV file at the given path to a vector of pairs of vectors of doubles and strings
    vector<pair<vector<double>, string>> information = CSVToInfo(path);
    // This line creates a new DistanceClass object
    DistanceClass distanceClass;
    // This line creates a new empty vector of doubles
    vector<double> test;
    // This loop runs indefinitely until a valid vector of doubles is entered
    while (true) {
        // This line attempts to get a vector of doubles from the user
        if (!distanceClass.getVector(&test)) {
            // If the user did not enter a valid vector of doubles, this line clears the vector
            test.clear();
            // This line continues the loop, prompting the user to enter a valid vector of doubles again
            continue;
        } else {
            // If the user entered a vector of doubles, this line checks if the vector has the correct size
            if (test.size() != information[0].first.size()) {
                // If the vector does not have the correct size, this line clears the vector
                test.clear();
                // This line prints an error message to the standard error stream
                cerr << "wrong size vector" << endl;
                // This line continues the loop, prompting the user to enter a valid vector of doubles again
                continue;
            } else {
                // If the vector has the correct size, this line exits the loop
                break;
            }
        }
    }
    // After the loop has exited, this line classifies the vector of doubles using the information from the
    // CSV file, the value of k, and the distance type
    string result = classify(test, information, k, disType);
    return result;
}


// This function is part of the Classification class
vector<pair<vector<double>, string>> Classification::CSVToInfo(
        // This function takes the path to a CSV file as input
        string path
) {
    // This line creates a new empty vector of pairs of vectors of doubles and strings
    vector<pair<vector<double>, string>> information;
    // This line creates a new ReadFile object
    ReadFile readFile;
    // This line creates a new DistanceClass object
    DistanceClass distanceClass;
    // This line reads the CSV file at the given path and stores the data in a 2D vector of strings
    vector<vector<string>> temp = readFile.ReadCSVByPath(path);
    // This loop iterates over each row of the CSV file
    for (int i = 0; i < temp.size(); ++i) {
        // This line creates a new empty vector of doubles
        vector<double> vTemp;
        // This line creates an empty string to store the class name
        string className = "";
        // This loop iterates over each element in the current row of the CSV file
        for (int j = 0; j < temp.at(i).size(); ++j) {
            // If the current element is not the last element in the row (i.e. not the class name), this line converts the string to a double and adds it to the vector of doubles
            if (j != temp.at(i).size() - 1) {
                double x = distanceClass.checkValidation(temp.at(i).at(j));
                vTemp.push_back(x);
            } else {
                // If the current element is the last element in the row (i.e. the class name), this line sets the class name to the string
                className = temp.at(i).at(j);
            }
        }
        // This line creates a new pair consisting of the vector of doubles and the class name, and adds it to the vector of pairs
        pair<vector<double>, string> pairTemp(vTemp, className);
        information.push_back(pairTemp);
    }

    // This line returns the vector of pairs
    return information;
}


// This function is part of the Classification class
string Classification::classify(
        // This function takes a vector of doubles representing a test case as input
        vector<double> test,
        // This function takes a vector of pairs of vectors of doubles and strings representing the training data as input
        vector<pair<vector<double>, string>> information,
        // This function takes an integer k as input
        int k,
        // This function takes a string representing the distance type to use as input
        string disType
) {
    if (k > information.size()) {
        k = information.size();
    }
    // This line creates a new Knn object
    Knn knn;
    // This line calls the ClosestsNeighbors function on the Knn object,
    // passing the test case, training data, value of k, and distance type as arguments, and stores the returned class in a string
    string chosenClass = knn.ClosestsNeighbers(k, disType, information, test);
    return chosenClass;
}

string Classification::classifyTestByTrain(vector<string> testVector, vector<vector<string>> trainCSV, int k, string disType) {
    DistanceClass distanceClass;
    // This line creates a new empty vector of pairs of vectors of doubles and strings
    vector<pair<vector<double>, string>> information;
    // This loop iterates over each row of the CSV file
    for (int i = 0; i < trainCSV.size(); ++i) {
        // This line creates a new empty vector of doubles
        vector<double> vTemp;
        // This line creates an empty string to store the class name
        string className = "";
        // This loop iterates over each element in the current row of the CSV file
        for (int j = 0; j < trainCSV.at(i).size(); ++j) {
            // If the current element is not the last element in the row (i.e. not the class name), this line converts the string to a double and adds it to the vector of doubles
            if (j != trainCSV.at(i).size() - 1) {
                double x = distanceClass.checkValidation(trainCSV.at(i).at(j));
                if(x == DBL_MAX) {
                    cout << "input was not a num" << endl;
                    return "input was not a number";
                }
                vTemp.push_back(x);
            } else {
                // If the current element is the last element in the row (i.e. the class name), this line sets the class name to the string
                className = trainCSV.at(i).at(j);
            }
        }
        // This line creates a new pair consisting of the vector of doubles and the class name, and adds it to the vector of pairs
        pair<vector<double>, string> pairTemp(vTemp, className);
        information.push_back(pairTemp);
    }
    // This line creates a new empty vector of doubles
    vector<double> vTemp;
    // This loop iterates over each element in the current row of the CSV file

    for (int j = 0; j < testVector.size(); ++j) {
        // If the current element is not the last element in the row (i.e. not the class name), this line converts the string to a double and adds it to the vector of doubles
        double x = distanceClass.checkValidation(testVector.at(j));
        cout << x << endl;
        if(x >= DBL_MAX-1000000) {
            cout << "input was not a num" << endl;
            return "input was not a number";
        }
        vTemp.push_back(x);
    }
    string finalClassName = classify(vTemp, information, k, disType);
    return finalClassName;
}