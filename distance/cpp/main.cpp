

#include "distance/h/main.h"
//a function that checks if an input is a number (double) and if so returns it
double checkValidation(string str) {
    double x = 0;
    //a flag to check if double
    bool flag = false;
    //trying to convert to a number
    try {
        //a variable to save the size of the conversion
        size_t pos;
        //stod is string to double, and the size is being saved as pos
        x = stod(str, &pos);
        //if the sizes of the original and the converted number aren't the same, that means
        //the string was not converted properly and that was probably not a number
        if (str.size() != pos) {
            exception e;
            //right now throws an empty exception
            throw e;
        //that means it was a number
        } else {
            flag = true;
        }
    }
    catch (exception &e) {
        //prints an error
        cerr << "The input was unsuccessful." << endl;
    }
    //if the flag is true that means the string was successfully converted into a double
    if (flag) {
        return x;
    }
}
//a function to get a new vector from the user
vector<double> getVector() {
    vector<double> v;
    cout << "enter a vector" << endl;
    //a while to get each number separated by spaces
    do {
        string x;
        cin >> x;
        //checks if the input is a number per input (per spaces)
        double num = checkValidation(x);
        //pushes number into the vector
        v.push_back(num);
        //just a print for checking
        cout << setprecision(10) << num << endl;
    //stops when he presses enter
    } while (cin.get() != '\n');
}
int main() {
    vector<double> v1 = getVector();
    vector<double> v2 = getVector();
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

