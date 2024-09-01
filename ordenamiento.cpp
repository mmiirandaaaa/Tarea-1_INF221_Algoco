#include<bits/stdc++.h>
using namespace std;

void print(int *arr, int n){
	cout << "[" << arr[0];
	for(int i=1; i<n; i++){
		cout << ", " << arr[i];
	}
	cout << "]\n";
}

void swap(int *arr, int i, int j){
	int aux = arr[i];
	arr[i] = arr[j];
	arr[j] = aux;
}

void insertion_sort(int *arr, int n){
	for(int i=1; i<n; i++){
		int j=i;
		for(int k=j; k>0; k--){
			if(arr[k-1] > arr[k]){
				swap(arr,k,k-1);
			}
		}
	}
}



int main(){
	int a[5]={8,2,3,10,9};
	int n=5;
	cout << "ARREGLO NO ORDENADO\n";
	print(a,n);
	insertion_sort(a,n);
	cout << "\nARREGLO ORDENADO\n";
	print(a,n);

	return 0;
}