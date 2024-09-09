#include <bits/stdc++.h>
#include "Matrices.h"
#include "Ordenamiento.h"

using namespace std;
using namespace chrono;

int M; int N;

int main(){
	srand(time(NULL));

  	//ALGORITMOS DE ORDENAMIENTO

	// int n=7;
	// int a[n]={20,7,1,3,4,10,15};
	// cout << "ARREGLO NO ORDENADO\n";
	// print(a,n);
	// QuickSort(a,0,n);
	// cout << "\nARREGLO ORDENADO\n";
	// print(a,n);

	M = 100; N = 100;
	vector<vector<int>> A(M, vector<int>(N));
	vector<vector<int>> B(M, vector<int>(N));
	PoblarMatriz(A); PoblarMatriz(B);
	vector<vector<int>> C(M, vector<int>(N));
	auto start = high_resolution_clock::now();
	MultCubico(A, B, C);
	auto end = high_resolution_clock::now();
	cout << duration_cast<seconds>(end - start).count() << '\n';
	
	return 0;
}