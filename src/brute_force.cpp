#include <iostream>
#include <vector>
#include "brute_force.h"

using namespace std;

pair<int, int> sigma(vector<pair<int, pair<int, int>>> subconjunto) {
    int acumBeneficio = 0;
    int acumContagio = 0;
    for (int i = 0; i < subconjunto.size(); i++) {
        acumBeneficio = acumBeneficio + subconjunto[i].second.first;
        acumContagio = acumContagio + subconjunto[i].second.second;
    }
    return make_pair(acumBeneficio, acumContagio);
}

void recParts(vector<pair<int, pair<int, int>>>& locales, vector<vector<pair<int, pair<int, int>>> >& res, vector<pair<int, pair<int, int>>>& subset, int index) {
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

int calculoBeneficioBF(vector<pair<int, pair<int, int>>> locales, int M) {
    vector<vector<pair<int, pair<int, int>>>> partes = parts(locales);
    int maxBeneficio = 0;

    for (int i = 0; i < partes.size(); ++i) {
        bool noHayContiguos = true;
        for (int j = 1; j < partes[i].size(); j++) {
            if (partes[i][j].first == partes[i][j-1].first+1)
            {
                noHayContiguos = false;
                break;
            }
        }
        if (!noHayContiguos) {
            continue;
        }
        pair<int, int> sumaSubParte = sigma(partes[i]);
        if (sumaSubParte.first >= maxBeneficio) {
        if (sumaSubParte.second <= M) {
            maxBeneficio = sumaSubParte.first;
        }
        }
    }

    return maxBeneficio;
}
