#include <vector>

using namespace std;

int calculoBeneficioDPMemo(vector<vector<vector<int>>>& memo, vector<int>& b, vector<int>& c, int i, int k, int prevTaken);
int calculoBeneficioDP(vector<int>& b, vector<int>& c, int M);