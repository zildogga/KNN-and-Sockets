

#include "distance/h/main.h"
//a function to get a new vector from the user
void getVector(vector<double>* v) {
    //vector<double> v;
    cout << "enter a vector" << endl;
    //a while to get each number separated by spaces
    do {
        string x;
        cin >> x;
        //checks if the input is a number per input (per spaces)
        double num;
        num = distanceClass().checkValidation(x);
        //pushes number into the vector
        (*v).push_back(num);
        //just a print for checking
        cout << setprecision(10) << num << endl;
    //stops when he presses enter
    } while (cin.get() != '\n');
}
int main() {
    vector<double> v1;
    vector<double> v2;
    getVector(&v1);
    getVector(&v2);
    if(v1.size()!=v2.size()) {
        cerr << "The vectors aren't the same size" << endl;
        return 0;
    }
    canberra c;
    chebyshev ch;
    minkowski m;
    euclidean euc;
    manhattan man;
    cout << c.distance(v1,v2) << "\n";
    cout << ch.distance(v1,v2) << "\n";
    cout << m.distance(v1,v2) << "\n";
    cout << euc.distance(v1,v2) << "\n";
    cout << man.distance(v1,v2) << "\n";

    return 0;
}

