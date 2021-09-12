#include "dynamic_programming.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

int calculoBeneficioDPMemo(vector<vector<vector<int>>>& memo, vector<int>& b, vector<int>& c, int index, int k, int prevShopClosed) {
    if (k < 0) return -1; // suma de contagios supera limite M
    if (memo[index][k][prevShopClosed] == -2) { // calculo buscado indefinido en la estructura de memoizacion
        if (index == 0) {
	    // ultimo local y su contagio no es mayor que M, entonces asignamos a la posicion en memo el beneficio 
            memo[index][k][prevShopClosed] = prevShopClosed == 1 && c[index] <= k ? b[index] : 0;
        }
        else if (prevShopClosed) {
	    // si no estamos en el ultimo local, seguimos con los llamados recursivos
            int skipCurrent = calculoBeneficioDPMemo(memo, b, c, index - 1, k, 1);
            int countCurrent = calculoBeneficioDPMemo(memo, b, c, index - 1, k - c[index], 0);
            if (countCurrent != -1)
                countCurrent += b[index];

            memo[index][k][prevShopClosed] = skipCurrent > countCurrent ? skipCurrent : countCurrent;
        }
        else {
            memo[index][k][prevShopClosed] = calculoBeneficioDPMemo(memo, b, c, index - 1, k, 1);
        }
    }

    return memo[index][k][prevShopClosed];
}

int calculoBeneficioDP(vector<int>& b, vector<int>& c) {
    int M = 45;
	vector<int> undefinedPair;
	undefinedPair.push_back(-2);
	undefinedPair.push_back(-2);
	vector<vector<int>> rows(M, undefinedPair);
	vector<vector<vector<int>>> memo(b.size(), rows);
	return calculoBeneficioDPMemo(memo, b, c, b.size() - 1, M - 1, 0);
}
