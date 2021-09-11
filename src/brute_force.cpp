#include <iostream>
#include <vector>
#include <cmath>
#include "brute_force.h"

using namespace std;
int M = 45;

int calculoBeneficioBF(vector<int>& b, vector<int>& c, int index, int bSum, int cSum) {
    if (index >= b.size()) {
        // si llegue al final de los llamados recursivos y la suma de contagios es mayor a limite M
        // devuelvo el menor beneficio posible
        // caso contrario, devuelvo la suma de beneficios proveniente de los llamados recursivos
        if (cSum > M) {
            return 0;
        }
        return bSum;
    }

    int skipCurrent = calculoBeneficioBF(b, c, index+1, bSum, cSum);
    int countCurrent = calculoBeneficioBF(b, c, index+2, bSum+b[index], cSum+c[index]);

    return skipCurrent > countCurrent ? skipCurrent : countCurrent;
}
