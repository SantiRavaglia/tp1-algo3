#include "backtracking.h"
#include <algorithm>

int mejorBeneficio = 0;

int BTRec(vector<pair<int, pair<int, int>>> locales, int M, int n, int index, int sumBeneficio, int sumContagio) {
    if(index == n) {
        if (sumContagio > M) sumBeneficio = -1;
        return (sumBeneficio > mejorBeneficio) ? sumBeneficio : mejorBeneficio;
    }

    int noAgrego =  BTRec(locales, M, n, sumBeneficio, sumContagio, index+1);
    int agrego = BTRec(locales, M, n, sumBeneficio+locales[index].second.first, sumContagio+locales[index].second.second, index+1);

    return max(noAgrego, agrego);
}

int calculoBeneficioBT(vector<pair<int, pair<int, int>>> locales, int M) {
    return BTRec(locales, M, locales.size(), 0, 0, 0);
}