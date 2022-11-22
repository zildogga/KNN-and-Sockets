

#include "distance/h/distanceClass.h"
//a function that checks if an input is a number (double) and if so returns it
double distanceClass::checkValidation(string str) {
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
        cerr << "The input was not a number." << endl;
        return DBL_MAX;
    }
    //if the flag is true that means the string was successfully converted into a double
    if (flag) {
        return x;
    }
}