

#include "Main.h"



int main(int argc, char* argv[]) {
    int k = 0;
    try {
        k = stoi(argv[1]);
    }
    catch(exception e) {
        cerr << "Error" << endl;
        return 1;
    }
    string path = argv[2];
    string disType = argv[3];
    Classification classification;
    //the path should be changed

    while(true) {
        classification.inputToClass(path, k, disType);
    }



//    ReadFile readFile;
//    vector<vector<string>> vtemp = readFile.ReadCSVByPath("C:\\Users\\Omer\\CLionProjects\\Advanced-Programming-1-Project\\Files\\iris_classified.csv");
//
//    //this is how you print a vector of vectors
//    for (int i = 0; i < vtemp.size(); ++i) {
//        for (int j = 0; j < vtemp.at(i).size(); ++j) {
//            cout << vtemp.at(i).at(j) << endl;
//        }
//    }
//
//    vector<double> v1;
//    vector<double> v2;
//    DistanceClass distanceClass;
//    //goes over all the vectors and gets the input into them
//    while(true) {
//        //checks if the size is 0, if it is there was no input in the vector yet
//        if (!v1.size()) {
//            //cout << "Enter the first vector : " << endl;
//            //if the vector wasn't successfully inserted, we need to clear it and go beck to the start of the loop
//            if (!distanceClass.getVector(&v1)) {
//                v1.clear();
//                //goes back to the start of the loop
//                continue;
//            }
//        }
//        //checks if the size is 0, if it is there was no input in the vector yet
//        if (!v2.size()) {
//            //cout << "Enter the second vector : " << endl;
//            //if the vector wasn't successfully inserted, we need to clear it and go beck to the start of the loop
//            if (!distanceClass.getVector(&v2)) {
//                v2.clear();
//                //goes back to the start of the loop
//                continue;
//            }
//        }
//        //if the sizes aren't the same we cannot call the algorithms
//        if (v1.size() != v2.size()) {
//            cerr << "The vectors aren't the same size" << endl;
//            //clears the second vector
//            v2.clear();
//            //goes back to the start of the loop
//            continue;
//        }
//        break;
//    }
//    //an instance for each algorithm
//    Canberra c;
//    Chebyshev ch;
//    Minkowski m;
//    Euclidean euc;
//    Manhattan man;
//    //prints all the results
//    // set precision to the double numbers, if the number is int print x.0
//    cout << setprecision(17);
//    cout << euc.distance(v1, v2);
//    if ((int)euc.distance(v1, v2) == euc.distance(v1, v2)) {
//        cout << ".0";
//    }
//    cout << endl;
//    cout << man.distance(v1, v2);
//    if ((int)man.distance(v1, v2) == man.distance(v1, v2)) {
//        cout << ".0";
//    }
//    cout << endl;
//    cout << ch.distance(v1, v2);
//    if ((int)ch.distance(v1, v2) == ch.distance(v1, v2)) {
//        cout << ".0";
//    }
//    cout << endl;
//    cout << c.distance(v1, v2);
//    if ((int)c.distance(v1, v2) == c.distance(v1, v2)) {
//        cout << ".0";
//    }
//    cout << endl;
//    cout << m.distance(v1, v2);
//    if ((int)m.distance(v1, v2) == m.distance(v1, v2)) {
//        cout << ".0";
//    }
//    cout << endl;
//
//
//    //returns 0 to end the Main
//    return 0;
}

