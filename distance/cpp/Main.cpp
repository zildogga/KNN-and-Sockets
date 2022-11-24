

#include "distance/h/Main.h"

//a function to get a new vector from the user
bool getVector(vector<double> *v) {
    //a while to get each number separated by spaces
    do {
        string x;
        cin >> x;
        //checks if the input is a number per input (per spaces)
        double num;
        num = DistanceClass().checkValidation(x);
        //if the num is max double that means we had an error
        if (num == DBL_MAX) {
            //clears the cin
            cin.clear();
            fflush(stdin);
            return false;
        }
        //pushes number into the vector
        (*v).push_back(num);
        //stops when he presses enter, might have spaces before, so we have to get rid of them
        while (cin.peek() == ' ') {
            cin.get();
        }
    } while (cin.peek() != '\n');
    return true;
}

int main() {
    vector<double> v1;
    vector<double> v2;
    //goes over all the vectors and gets the input into them
    while(true) {
        //checks if the size is 0, if it is there was no input in the vector yet
        if (!v1.size()) {
            //cout << "Enter the first vector : " << endl;
            //if the vector wasn't successfully inserted, we need to clear it and go beck to the start of the loop
            if (!getVector(&v1)) {
                v1.clear();
                //goes back to the start of the loop
                continue;
            }
        }
        //checks if the size is 0, if it is there was no input in the vector yet
        if (!v2.size()) {
            //cout << "Enter the second vector : " << endl;
            //if the vector wasn't successfully inserted, we need to clear it and go beck to the start of the loop
            if (!getVector(&v2)) {
                v2.clear();
                //goes back to the start of the loop
                continue;
            }
        }
        //if the sizes aren't the same we cannot call the algorithms
        if (v1.size() != v2.size()) {
            cerr << "The vectors aren't the same size" << endl;
            //clears the second vector
            v2.clear();
            //goes back to the start of the loop
            continue;
        }
        break;
    }
    //an instance for each algorithm
    Canberra c;
    Chebyshev ch;
    Minkowski m;
    Euclidean euc;
    Manhattan man;
    //prints all the results
    // set precision to the double numbers, if the number is int print x.0
    cout << setprecision(17);
    cout << euc.distance(v1, v2);
    if ((int)euc.distance(v1, v2) == euc.distance(v1, v2)) {
        cout << ".0";
    }
    cout << endl;
    cout << man.distance(v1, v2);
    if ((int)man.distance(v1, v2) == man.distance(v1, v2)) {
        cout << ".0";
    }
    cout << endl;
    cout << ch.distance(v1, v2);
    if ((int)ch.distance(v1, v2) == ch.distance(v1, v2)) {
        cout << ".0";
    }
    cout << endl;
    cout << c.distance(v1, v2);
    if ((int)c.distance(v1, v2) == c.distance(v1, v2)) {
        cout << ".0";
    }
    cout << endl;
    cout << m.distance(v1, v2);
    if ((int)m.distance(v1, v2) == m.distance(v1, v2)) {
        cout << ".0";
    }
    cout << endl;


    //returns 0 to end the Main
    return 0;
}

