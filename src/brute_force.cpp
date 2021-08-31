#include <iostream>
#include <vector>

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

int main() {
    pair<int, pair<int, int>> p1;
    p1.first = 0;
    p1.second.first = 50;
    p1.second.second = 10;

    pair<int, pair<int, int>> p2;
    p2.first = 1;
    p2.second.first = 25;
    p2.second.second = 10;

    pair<int, pair<int, int>> p3;
    p3.first = 2;
    p3.second.first = 10;
    p3.second.second = 20;

    pair<int, pair<int, int>> p4;
    p4.first = 3;
    p4.second.first = 20;
    p4.second.second = 30;

    pair<int, pair<int, int>> p5;
    p5.first = 4;
    p5.second.first = 15;
    p5.second.second = 20;

    vector<pair<int, pair<int, int>>> testV;
    testV.push_back(p1);
    testV.push_back(p2);
    testV.push_back(p3);
    testV.push_back(p4);
    testV.push_back(p5);

    // vector<vector<pair<int, pair<int, int>>>> partes = parts(testV);
    // for (int i = 0; i < partes.size(); ++i) {
    // 	cout << "[" << endl;
    // 	for (int k = 0; k < partes[i].size(); ++k) {
    // 		cout << "(" << partes[i][k].first << "," << partes[i][k].second << ")" << "-";
    // 	}
    // 	cout << "]" << endl;
    // }
    // cout << partes.size() << endl;

    cout << calculoBeneficioBF(testV, 45) << endl;

    return 0;
}
