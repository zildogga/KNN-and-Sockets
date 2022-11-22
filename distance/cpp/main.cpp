

#include "distance/h/main.h"

//a function to get a new vector from the user
bool getVector(vector<double> *v) {
    //vector<double> v;
    //a while to get each number separated by spaces
    do {
        string x;
        cin >> x;
        //checks if the input is a number per input (per spaces)
        double num;
        num = distanceClass().checkValidation(x);
        if (num == DBL_MAX) {
            cin.clear();
            fflush(stdin);
            return false;
        }
        //pushes number into the vector
        (*v).push_back(num);
        //just a print for checking
        //cout << setprecision(10) << num << endl;
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
    //a flag for each vector, if the input was correct will change to true
    bool flag = false;
    //flag2 is a flag to check if the vectors are the same size
    bool flag2 = false;

    while(!flag2) {
        while (!flag) {
            cout << "Enter the first vector : " << endl;
            if (getVector(&v1)) {
                flag = true;
            } else {
                v1.clear();
            }
        }
        flag = false;
        while (!flag) {
            cout << "Enter the second vector : " << endl;
            if (getVector(&v2)) {
                flag = true;
            } else {
                v2.clear();
            }
        }
        if (v1.size() != v2.size()) {
            cerr << "The vectors aren't the same size" << endl;
            v2.clear();
        }
        else {
            flag2 = true;
        }
    }
    canberra c;
    chebyshev ch;
    minkowski m;
    euclidean euc;
    manhattan man;
    cout << "And the results are:" << endl;
    cout << "Canberra : " << c.distance(v1, v2) << "\n";
    cout << "Chebyshev : " << ch.distance(v1, v2) << "\n";
    cout << "Minkowski : " << m.distance(v1, v2) << "\n";
    cout << "Euclidean : " << euc.distance(v1, v2) << "\n";
    cout << "Manhattan : " << man.distance(v1, v2) << "\n";

    return 0;
}

