//
// Created by omer on 1/18/23.
//

#include "StandardIO.h"

string StandardIO::read() {
    string text;
    cin.ignore();
    getline(cin,text);
    cout << text << endl;
    return text;
}

void StandardIO::write(string text) {
    cout << text << endl;
}

