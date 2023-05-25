/*
 * Advanced Programming 1 Project
 * Ofir Goldberg - 315141325
 * Omer Groman - 207163452
*/

#include "StandardIO.h"

string StandardIO::read() {
    string text;
    // ignore any remaining characters in the input buffer
    cin.ignore();
    // read a line from standard input
    getline(cin,text);
    return text;
}

void StandardIO::write(string text) {
    // print the text
    cout << text << endl;
}

