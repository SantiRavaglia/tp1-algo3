#include "brute_force.h"
#include "backtracking.h"
#include "dynamic_programming.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <chrono>
#include <set>
#include <map>
#include <limits>
#include <random>
#include <fstream>
#include <sstream>

using namespace std;

int n, M;
vector<int> b,c;
int INFTY = 10e6;

static vector<int> generate_data(int n)
{
    vector<int> res;
    for(int i = 0; i < n; i++){
        res.push_back(rand() % 100 + 1);
    }
    return res;
}

int main(int argc, char **argv) {
    int cotaOptB1 = 0;
    int cotaOptB2 = 0;
    bool s = false;
    for (int i = 0; i < b.size(); i++) {
        cotaOptB1 += s ? b[i] : 0;
        cotaOptB2 += !s ? b[i] : 0;
        s = !s;
    }
    int cotaOptB = max(cotaOptB1, cotaOptB2);
    if (argc < 2)
   {
      std::cout << "Faltan argumentos!\n";
      return 0;
   }
   map<string, string> algoritmos_implementados = {
		{"BF", "Fuerza Bruta"}, {"BT", "Backtracking con podas"}, {"BT-F", "Backtracking con poda por factibilidad"}, 
		{"BT-O", "Backtracking con poda por optimalidad"}, {"DP", "Programacion dinámica"}
	};
    if (algoritmos_implementados.find(argv[1]) == algoritmos_implementados.end())
	{
		cout << "Algoritmo no encontrado: " << argv[1] << endl;
		cout << "Los algoritmos existentes son: " << endl;
		for (auto& alg_desc: algoritmos_implementados) cout << "\t- " << alg_desc.first << ": " << alg_desc.second << endl;
		return 0;
    }
	string algoritmo = argv[1];

    cin >> n >> M;
    c.assign(n, 0);
    b.assign(n, 0);
    for (int i = 0; i < n; ++i) {
        cin >> b[i] >> c[i];
    }

    int optimum;
    double total_time;
    auto start = chrono::steady_clock::now();
	if (algoritmo == "BF")
	{
		optimum = calculoBeneficioBF(b, c, M, 0, 0, 0);
	}
	else if (algoritmo == "BT")
	{
		optimum = calculoBeneficioBT(b, c, M, 0, 0, 0, cotaOptB, true, true);
	}
    else if (algoritmo == "BT-F")
	{
		optimum = calculoBeneficioBT(b, c, M, 0, 0, 0, cotaOptB, false, true);
	}
	else if (algoritmo == "BT-O")
	{
		optimum = calculoBeneficioBT(b, c, M, 0, 0, 0, cotaOptB, true, false);
	}
	else if (algoritmo == "DP")
	{
		optimum = calculoBeneficioDP(b, c, M);
	}
	auto end = chrono::steady_clock::now();
	total_time = chrono::duration<double, milli>(end - start).count();
    total_time = total_time;

    clog << total_time << endl;

    return 0;

// ------------------------------------------

    

    // int resBF = calculoBeneficioBF(b, c, M, 0, 0, 0);
    
    // int cotaOptB1 = 0;
    // int cotaOptB2 = 0;
    // bool s = false;
    // for (int i = 0; i < b.size(); i++) {
    //     cotaOptB1 += s ? b[i] : 0;
    //     cotaOptB2 += !s ? b[i] : 0;
    //     s = !s;
    // }
    // int cotaOptB = max(cotaOptB1, cotaOptB2);
    // int resBT = calculoBeneficioBT(b, c, M, 0, 0, 0, cotaOptB);
    // int resDP = calculoBeneficioDP(b, c, M);

    // cout << resBF << ", " << resBT << ", " << resDP << endl;
}
