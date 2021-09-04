#include <vector>

using namespace std;

int BTRec(vector<pair<int, pair<int, int>>> locales, int index, int sumBeneficio, int sumContagio, int currentIdx, int M);

int calculoBeneficioBT(vector<pair<int, pair<int, int>>> locales, int M);