#include "backtracking.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;
int M = 45;

int calculoBeneficioBT(vector<int>& b, vector<int>& c, int index, int bSum, int cSum, int cotaOptB) {
    // chequeo de final de llamados recursivos
    if (index >= b.size()) {
        return bSum;
    }

    if (cSum + c[index] > M) { // poda por factibilidad, porque se que no existe una solucion factible a partir de este punto
        return 0;
    }
    
    if (bSum == cotaOptB) { // poda por optimalidad, no existe una solucion mejor que mejor cota de beneficios
        return bSum;
    }

    // llamados recursivos
    int skipCurrent = calculoBeneficioBT(b, c, index+1, bSum, cSum);
    int countCurrent = calculoBeneficioBT(b, c, index+2, bSum+b[index], cSum+c[index]);

    return skipCurrent > countCurrent ? skipCurrent : countCurrent;
}
