#include <iostream>
#include <vector>
#include "brute_force.h"
#include "backtracking.h"
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

    int resBF = calculoBeneficioBF(b, c, 0, 0, 0);
    
    int cotaOptB1 = 0;
    int cotaOptB2 = 0;
    bool s = false;
    for (int i = 0; i < b.size(); i++) {
        cotaOptB1 += s ? b[i] : 0;
        cotaOptB2 += !s ? b[i] : 0;
        s = !s;
    }
    int cotaOptB = max(cotaOptB1, cotaOptB2);
    int resBT = calculoBeneficioBT(b, c, 0, 0, 0, cotaOptB);
    int resDP = calculoBeneficioDP(b, c);

    cout << resBF << ", " << resBT << ", " << resDP << endl;

    return 0;
}
