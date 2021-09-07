#include "dynamic_programming.h"
#include <algorithm>
#include <vector>
#include <cmath>
int M = 45;
// [20, 50, 10, 15 25]
// [10, 25, 40, 15, 20]
// [, 75, 35, 25, 25]
int calculoBeneficioDPMemo(vector<int>& memo, vector<int>& b, vector<int>& c, int index, int bSum, int cSum) {
    if (index >= b.size()) {
        return bSum;
    }

    if (cSum + c[index] > M) { // poda por factibilidad, porque se que no existe una solucion factible a partir de este punto
        return 0;
    }

	int skipCurrent, countCurrent;
	if (index+1 < memo.size() && memo[index+1] != -1) {
		skipCurrent = memo[index+1];
	} else {
		skipCurrent = calculoBeneficioDPMemo(memo, b, c, index+1, bSum, cSum);
		memo[index+1] = skipCurrent;
	}

	if (memo[index] != -1) {
		countCurrent = memo[index];
	} else {
		countCurrent = calculoBeneficioDPMemo(memo, b, c, index+2, bSum+b[index], cSum+c[index]);
		memo[index] = countCurrent;
	}

    return skipCurrent > countCurrent ? skipCurrent : countCurrent;
}

int calculoBeneficioDP(vector<int>& b, vector<int>& c) {
	vector<int> memo(b.size(), -1);
	return calculoBeneficioDPMemo(memo, b, c, 0, 0, 0);
}