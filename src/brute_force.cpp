#include <iostream>
#include <vector>
#include <cmath>
#include "brute_force.h"

using namespace std;
int M = 45;

int calculoBeneficioBF(vector<int>& b, vector<int>& c, int index, int bSum, int cSum) {
    if (index >= b.size()) {
        if (cSum + c[index] > M) {
            return 0;
        }
        return bSum;
    }

    int skipCurrent = calculoBeneficioBF(b, c, index+1, bSum, cSum);
    int countCurrent = calculoBeneficioBF(b, c, index+2, bSum+b[index], cSum+c[index]);

    return skipCurrent > countCurrent ? skipCurrent : countCurrent;
}