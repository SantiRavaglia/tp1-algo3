#include <iostream>
#include <vector>
#include <cmath>
#include "brute_force.h"

using namespace std;
int M = 45;

pair<int, int> sigma(vector<pair<int, pair<int, int>>> subconjunto) {
    int acumBeneficio = 0;
    int acumContagio = 0;
	int currentIdx;
	if (subconjunto.size() != 0) {
		currentIdx = subconjunto[0].first;
	}
    for (int i = 0; i < subconjunto.size(); i++) {
		if (abs(currentIdx - subconjunto[i].first) == 1) {
			acumContagio = M + 1; //sobrepasa el limite de contagio
			break;
		}
        acumBeneficio = acumBeneficio + subconjunto[i].second.first;
        acumContagio = acumContagio + subconjunto[i].second.second;
		currentIdx = subconjunto[i].first;
    }

    return make_pair(acumBeneficio, acumContagio);
}

void recParts(vector<pair<int, pair<int, int>>>& locales, vector<vector<pair<int, pair<int, int>>>>& res, vector<pair<int, pair<int, int>>>& subset, int index) {
    res.push_back(subset);
    for (int i = index; i < locales.size(); i++) {
        subset.push_back(locales[i]);
        recParts(locales, res, subset, i + 1);
        subset.pop_back();
    }

    return;
}

vector<vector<pair<int, pair<int, int>>>> parts(vector<pair<int, pair<int, int>>>& locales) {
    vector<pair<int, pair<int, int>>> subset;
    vector<vector<pair<int, pair<int, int>>>> res;
    int index = 0;
    recParts(locales, res, subset, index);

    return res;
}

void calculoBeneficioRec(int &maxBeneficio, vector<vector<pair<int, pair<int, int>>>> &partes, int &index) {
	if (index == partes.size()){
		return;
    }
	
	pair<int, int> sumaSubParte = sigma(partes[index]);
	if (sumaSubParte.second <= M && sumaSubParte.first > maxBeneficio) {
		maxBeneficio = sumaSubParte.first;
	}
	index++;
	calculoBeneficioRec(maxBeneficio, partes, index);
}

int calculoBeneficioBF(vector<pair<int, pair<int, int>>> locales) {
    vector<vector<pair<int, pair<int, int>>>> partes = parts(locales);
    int maxBeneficio = 0;
	int index = 0;
	calculoBeneficioRec(maxBeneficio, partes, index);

    return maxBeneficio;
}