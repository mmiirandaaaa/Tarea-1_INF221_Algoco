#include <bits/stdc++.h>
#include "Matrices.h"
#include "Ordenamiento.h"
#define ll long long


using namespace std;
using namespace chrono;

void probar(vector<int> A, ll N, string algoritmo, ofstream &results){
	results << algoritmo << ",";
    auto start = high_resolution_clock::now();
    
    if(algoritmo.compare("InsertionSort") == 0){
        InsertionSort(A, N);
    }
    else if(algoritmo.compare("C++Sort") == 0){
        sort(A.begin(), A.end());
    }
    else if(algoritmo.compare("QuickSort") == 0){
        QuickSort(A, 0, N-1);
    }
    else if(algoritmo.compare("MergeSort") == 0){
        MergeSort(A, 0, N-1);
    }

    auto end = high_resolution_clock::now();
    duration<double, milli> duration = end - start;
    results << duration.count() << "," << N << ",";
}

int main(){
	srand(time(NULL));

  	//ALGORITMOS DE ORDENAMIENTO
	ofstream results; results.open("resultados.csv");
	fstream data; data.open("Ordenamiento_Dataset.txt");
	results << "Algoritmo,Tiempo,Tamaño,Orden\n";
	for(int z=0; z<10; z++){ // 0: N=10000; 1: N=20000; 2: N=30000; ...
		ll N; data >> N;
		vector<int> A(N); //Arreglo ordenado ascendente
		vector<int> B(N); //Arreglo ordenado descendente
		vector<int> C(N); //Arreglo desordenado
		
		for (int i = 0; i < N; i++) data >> A[i];
        for (int i = 0; i < N; i++) data >> B[i];
        for (int i = 0; i < N; i++) data >> C[i];

        // Probar todos los algoritmos
        vector<string> algoritmos = {"InsertionSort", "MergeSort", "QuickSort", "C++Sort"};

        for(const auto &algoritmo : algoritmos){
            probar(A, N, algoritmo, results); results << "Ascendente\n";
            probar(B, N, algoritmo, results); results << "Descendente\n";
            probar(C, N, algoritmo, results); results << "Desordenado\n";
        }
	}

	results.close();
	data.close();

	// int m=3; int n=2;
	// int l=2; int r=4;
	// vector<vector<int>> A(m, vector<int>(n));
	// vector<vector<int>> B(l, vector<int>(r));
	// PoblarMatriz(A); PoblarMatriz(B);
	// vector<vector<int>> C(m, vector<int>(r));
	// auto start = high_resolution_clock::now();
	// MultCubico(A, B, C);
	// auto end = high_resolution_clock::now();
	// cout << duration_cast<seconds>(end - start).count() << "\n";
	// cout << "A:\n";print(A);cout << "B:\n";print(B);cout << "\n";
	// cout << "C:\n"; print(C);
	
	return 0;
}