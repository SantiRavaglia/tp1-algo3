#include "backtracking.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int calculoBeneficioBT(vector<int>& b, vector<int>& c, int M, int index, int bSum, int cSum, int cotaOptB, bool podaOpt, bool podaFact) {
    // chequeo de final de llamados recursivos
    if (index >= b.size()) {
        return bSum;
    }

    if (podaFact && cSum + c[index] > M) { // poda por factibilidad, porque se que no existe una solucion factible a partir de este punto
        return 0;
    }
    
    if (podaOpt && bSum + b[index] == cotaOptB) { // poda por optimalidad, no existe una solucion mejor que mejor cota de beneficios
        return bSum+b[index];
    }

    // llamados recursivos
    int skipCurrent = calculoBeneficioBT(b, c, M, index+1, bSum, cSum, cotaOptB, podaOpt, podaFact);
    int countCurrent = calculoBeneficioBT(b, c, M, index+2, bSum+b[index], cSum+c[index],cotaOptB, podaOpt, podaFact);

    return skipCurrent > countCurrent ? skipCurrent : countCurrent;
}
