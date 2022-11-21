

#include "distance/h/main.h"

double checkValidation(string str) {
    double x = 0;
    bool flag = false;
    try {
        size_t pos;
        x = stod(str, &pos);
        if (str.size() != pos) {
            exception e;
            throw e;
        } else {
            flag = true;
        }
    }
    catch (exception &e) {
        cerr << "wrong" << endl;
    }
    if (flag) {
        return x;
    }
}

vector<double> getVector() {
    vector<double> v;
    cout << "enter a vector" << endl;
    do {
        string x;
        cin >> x;
        double num = checkValidation(x);
        v.push_back(num);
        cout << setprecision(10) << num << endl;
    } while (cin.get() != '\n');
}
int main() {
    vector<double> v1 = getVector();
    vector<double> v2 = getVector();
























//    std::cout << "hello\n";
//    std::vector<double> v1 = {1.5,4.22,3.686};
//    std::vector<double> v2 = {2,5.7163,3.6};
    canberra c;
    chebyshev ch;
    minkowski m;
    euclidean euc;
    manhattan man;

   std::cout << c.distance(v1,v2) << "\n";
    std::cout << ch.distance(v1,v2) << "\n";
    std::cout << m.distance(v1,v2) << "\n";
    std::cout << euc.distance(v1,v2) << "\n";
    std::cout << man.distance(v1,v2) << "\n";

    return 0;
}

