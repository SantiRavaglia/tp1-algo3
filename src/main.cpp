#include <iostream>
#include <vector>
#include "brute_force.h"
// #include "backtracking.h"
#include <algorithm>

using namespace std;

int main() {
    pair<int, pair<int, int>> p1;
    p1.first = 0;
    p1.second.first = 50;
    p1.second.second = 10;

    pair<int, pair<int, int>> p2;
    p2.first = 1;
    p2.second.first = 25;
    p2.second.second = 10;

    pair<int, pair<int, int>> p3;
    p3.first = 2;
    p3.second.first = 10;
    p3.second.second = 20;

    pair<int, pair<int, int>> p4;
    p4.first = 3;
    p4.second.first = 20;
    p4.second.second = 30;

    pair<int, pair<int, int>> p5;
    p5.first = 4;
    p5.second.first = 15;
    p5.second.second = 20;

    vector<pair<int, pair<int, int>>> testV;
    testV.push_back(p1);
    testV.push_back(p2);
    testV.push_back(p3);
    testV.push_back(p4);
    testV.push_back(p5);

    int resBF = calculoBeneficioBF(testV);
    // int resBT = calculoBeneficioBT(testV, 45);

    cout << resBF << endl;

    return 0;
}