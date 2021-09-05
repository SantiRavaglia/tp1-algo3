#include <vector>

using namespace std;

int BFRec(vector<pair<int, pair<int, int>>> locales, int M, int index, int sumBeneficio, int sumContagio, vector<int> vecIndex);

int calculoBeneficioBF(vector<pair<int, pair<int, int>>> locales);