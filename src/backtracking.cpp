#include "backtracking.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;
int M = 45;

int calculoBeneficioBT(vector<int>& b, vector<int>& c, int index, int bSum, int cSum) {
    if (index >= b.size()) {
        return bSum;
    }

    if (cSum + c[index] > M) { // poda por factibilidad, porque se que no existe una solucion factible a partir de este punto
        return 0;
    }

    // hila fino en si es poda o no
    int skipCurrent = calculoBeneficioBT(b, c, index+1, bSum, cSum);
    int countCurrent = calculoBeneficioBT(b, c, index+2, bSum+b[index], cSum+c[index]);

    return skipCurrent > countCurrent ? skipCurrent : countCurrent;
}

// int calculoBeneficioBT(vector<int>& b, vector<int>& c, int index, int bSum, int cSum, int prevIdx) {
//     // cout << bSum << endl;
//     if (index >= b.size()) {
//         return bSum;
//     }

//     if (cSum + c[index] > M) { // poda por factibilidad, porque se que no existe una solucion factible a partir de este punto
//         return 0;
//     }

//     int skipCurrent, countCurrent;
//     if (index == 0) {
//         skipCurrent = calculoBeneficioBT(b, c, index+1, bSum, cSum, prevIdx);
//         countCurrent = calculoBeneficioBT(b, c, index+2, bSum+b[index], cSum+c[index], prevIdx);
//     } else if (index == 1) {        
//         skipCurrent = calculoBeneficioBT(b, c, index+1, bSum, cSum, prevIdx);
//         countCurrent = calculoBeneficioBT(b, c, index+1, bSum+b[index], cSum+c[index], index);
//     } else {
//         if (index - prevIdx == 1) {
//             cout << bSum << endl;
//             return 0;
//         }
//         skipCurrent = calculoBeneficioBT(b, c, index+1, bSum, cSum, prevIdx);
//         countCurrent = calculoBeneficioBT(b, c, index+1, bSum+b[index], cSum+c[index], index);
//     }

//     return skipCurrent > countCurrent ? skipCurrent : countCurrent;
// }