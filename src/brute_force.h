#include <vector>

using namespace std;

pair<int, int> sigma(vector<pair<int, pair<int, int>>> subconjunto);

void recParts(vector<pair<int, pair<int, int>>>& locales, vector<vector<pair<int, pair<int, int>>> >& res, vector<pair<int, pair<int, int>>>& subset, int index);

vector<vector<pair<int, pair<int, int>>>> parts(vector<pair<int, pair<int, int>>>& locales);

int calculoBeneficioBF(vector<pair<int, pair<int, int>>> locales, int M);
