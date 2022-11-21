

#include "distance/h/main.h"
int main() {
    std::cout << "hello\n";
    std::vector<double> v1 = {1.5,4.22,3.686};
    std::vector<double> v2 = {2,5.7163,3.6};
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
