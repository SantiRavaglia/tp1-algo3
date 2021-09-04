#include <iostream>
#include <vector>
#include <cmath>
#include "brute_force.h"

using namespace std;

int mejorBeneficioBF = 0;

int BFRec(vector<pair<int, pair<int, int>>> locales, int M, int index, int sumBeneficio, int sumContagio, vector<int> vecIndex) {
    if(index == locales.size()) {
        if (sumContagio > M) sumBeneficio = 0;
        for(int i = 1; i < vecIndex.size(); i++) {
            if (abs(vecIndex[i] - vecIndex[i-1]) == 1) {
                return 0;
            } else {
                return (sumBeneficio > mejorBeneficioBF) ? sumBeneficio : mejorBeneficioBF;
            }
        }  
    }

    int noAgrego =  BFRec(locales, M, index+1, sumBeneficio, sumContagio, vecIndex);
    vecIndex.push_back(locales[index].first);
    int agrego = BFRec(locales, M, index+1, sumBeneficio+locales[index].second.first, sumContagio+locales[index].second.second, vecIndex);
}

int calculoBeneficioBF(vector<pair<int, pair<int, int>>> locales, int M) {
	vector<int> vecIndex;
    return BFRec(locales, M, 0, 0, 0, vecIndex);
}

