#include "backtracking.h"
#include <algorithm>
#include <vector>
#include <cmath>

// int mejorBeneficio = 0;

int BTRec(vector<pair<int, pair<int, int>>> locales, int index, int sumBeneficio, int sumContagio, int currentIdx, int M) {
    if(index == locales.size() || sumContagio > M) { //confio en la logica de cortocircuito de || en cpp
        return 0;
    }
    
    if (abs(currentIdx - locales[index].first) != 1) {
        currentIdx = locales[index].first;
    }
    int noAgrego =  BTRec(locales, index+1, sumBeneficio, sumContagio, currentIdx, M);
    int agrego = BTRec(locales, index+1, sumBeneficio+locales[index].second.first, sumContagio+locales[index].second.second, currentIdx, M);

    return max(noAgrego, agrego);
}

int calculoBeneficioBT(vector<pair<int, pair<int, int>>> locales, int M) {
    int currentIdx = 0;
    return BTRec(locales, 0, 0, 0, currentIdx, M);
}