//
// Created by ofir on 11/15/22.
//

#include "distance/h/main.h"

int main() {
    std::vector<double> v1 = {1.5, 2};
    std::vector<double> v2 = {0, 0};
    euclideanDistance euc;
    manhattanDistance man;
    double dis1 = euc.distance(v1, v2);
    double dis2 = man.distance(v1, v2);
    std::cout << "euclidean distance: " << dis1 << std::endl;
    std::cout << "manhattan distance: " << dis2;
    return 0;
}
