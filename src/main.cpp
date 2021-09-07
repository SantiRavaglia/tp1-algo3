#include <iostream>
#include <vector>
// #include "brute_force.h"
// #include "backtracking.h"
#include "dynamic_programming.h"
#include <algorithm>

using namespace std;

int main() {
    vector<int> b;
    b.push_back(50);
    b.push_back(25);
    b.push_back(10);
    b.push_back(20);
    b.push_back(15);
    vector<int> c;
    c.push_back(10);
    c.push_back(10);
    c.push_back(20);
    c.push_back(30);
    c.push_back(20);

    // int resBF = calculoBeneficioBF(b, c, 0, 0, 0);
    // int resBT = calculoBeneficioBT(b, c, 0, 0, 0);
    int resDP = calculoBeneficioDP(b, c);

    cout << resDP << endl;

    return 0;
}