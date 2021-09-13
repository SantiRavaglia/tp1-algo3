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
//     if (argc < 2)
//    {
//       std::cerr << "Faltan argumentos!\n";
//       return -1;
//    }
//    map<string, string> algoritmos_implementados = {
// 		{"BF", "Fuerza Bruta"}, {"BT", "Backtracking con podas"}, {"BT-F", "Backtracking con poda por factibilidad"}, 
// 		{"BT-O", "Backtracking con poda por optimalidad"}, {"DP", "Programacion dinámica"}
// 	};
//     if (algoritmos_implementados.find(argv[1]) == algoritmos_implementados.end())
// 	{
// 		cerr << "Algoritmo no encontrado: " << argv[1] << endl;
// 		cerr << "Los algoritmos existentes son: " << endl;
// 		for (auto& alg_desc: algoritmos_implementados) cerr << "\t- " << alg_desc.first << ": " << alg_desc.second << endl;
// 		return -1;
//     }
// 	string algoritmo = argv[1];

//     cin >> n >> M;
//     c.assign(n, 0);
//     b.assign(n, 0);
//     for (int i = 0; i < n; ++i) {
//         cin >> b[i] >> c[i];
//     }

    string algoritmo = "DP";
    string dataset = "mejor-caso-bt";
    int M = 50;
    int optimum;
    double total_time;
    vector<string> res;

    for (int i = 2; i <= 42; i+= 2)
    {
        b = generate_data(i);
        c = generate_data(i);
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
        total_time = total_time/1000;
        res.push_back(to_string(i) + "," + to_string(total_time) + "," + algoritmo + "," + dataset);
        clog << total_time << ", ";
        cout << optimum << " n = " << i << endl;
    }

    ofstream outfile;

    outfile.open("./python/resultados/dp.csv", ios_base::app);
    outfile << "n" << "," << "tiempo"  << ","  << "metodo"  << ","  << "dataset" << endl;
    for (int i = 0; i < res.size(); i++)
    {
        outfile << res[i] << endl;
    }

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
