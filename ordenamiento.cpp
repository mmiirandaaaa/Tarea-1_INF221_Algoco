#include<bits/stdc++.h>
#include "Ordenamiento.h"
using namespace std;

void PrintArr(vector<int> &arr, int n){
	cout << "[" << arr[0];
	for(int i=1; i<n; i++){
		cout << ", " << arr[i];
	}
	cout << "]\n";
}

void swap(vector<int> &arr, int i, int j){
	int aux = arr[i];
	arr[i] = arr[j];
	arr[j] = aux;
}

void InsertionSort(vector<int> &arr, int n){
	for(int i=1; i<n; i++){
		int j=i;
		for(int k=j; k>0; k--){
			if(arr[k-1] > arr[k]){
				swap(arr,k,k-1);
			}
		}
	}
}

void merge(vector<int> &A, int l, int m, int r){
	int nL = m-l+1; //largo de la mitad A[l:m] 
	int nR = r-m; // largo de la mitad A[m+1:r]
	vector<int> L(nL); vector<int> R(nR);
	
	for(int i=0; i<nL; i++){
		L[i] = A[l + i];
	}
	for(int i=0; i<nR; i++){
		R[i] = A[m+1 + i];
	}

	int i=0; int j=0; int k=l;

	while(i<nL && j<nR){
		if(L[i] <= R[j]){
			A[k] = L[i];
			i++;
		}
		else{
			A[k] = R[j];
			j++;
		}
		k++;
	}

	while(i<nL){
		A[k] = L[i];
		i++; k++;
	}

	while(j<nR){
		A[k] = R[j];
		j++; k++;
	}

}	


void MergeSort(vector<int> &A, int l, int r){
	if(l>=r){
		return;
	}
	int m = l + (r - l) / 2;
	MergeSort(A, l, m);
	MergeSort(A, m+1, r);
	merge(A, l,m,r);
}

int particion(vector<int> &A, int l, int r){
	int x = A[r]; //Pivote, es el último elemento del arreglo
	int i = l-1;
	for(int j=l; j<r; j++){
		if(A[j]<=x){
			i = i+1;
			swap(A,i,j);
		}
	}
	swap(A,i+1,r);
	return i+1;
}

void QuickSort(vector<int> &A, int l, int r){
	if(l<r){
		int q = particion(A,l,r);
		QuickSort(A,l,q-1);
		QuickSort(A,q+1,r);
	}
}