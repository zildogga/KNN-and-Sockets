//
// Created by omer on 1/18/23.
//

#include "StandardIO.h"

string StandardIO::read() {
    string text;
    cin >> text;
    return text;
}

void StandardIO::write(string text) {
    cout << text << endl;
}
