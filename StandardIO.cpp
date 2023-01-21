//
// Created by omer on 1/18/23.
//

#include "StandardIO.h"

char* StandardIO::read() {
    char* text;
    cin >> text;
    return text;
}

void StandardIO::write(string text) {
    cout << text << endl;
}

