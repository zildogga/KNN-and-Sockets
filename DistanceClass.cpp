#include "DistanceClass.h"
//a function that checks if an input is a number (double) and if so returns it
double DistanceClass::checkValidation(string str) {
    double x = 0;
    //a flag to check if double
    bool isDouble = false;
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
            isDouble = true;
        }
    }
    catch (exception &e) {
        //prints an error
        cerr << "The input was not a number." << endl;
        //returns the max double for exception reasons
        return DBL_MAX;
    }
    //if the flag is true that means the string was successfully converted into a double
    if (isDouble) {
        return x;
    }
    return DBL_MAX;
}

//a function to get a new vector from the user
bool DistanceClass::getVector(vector<double> *v) {
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