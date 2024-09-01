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

void merge(int *A, int l, int m, int r){
	int nL = m-l+1; //largo de la mitad A[l:m] 
	int nR = r-m; // largo de la mitad A[m+1:r]
	int L[nL]; int R[nR];
	
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


void merge_sort(int *A, int l, int r){
	if(l>=r){
		return;
	}
	int m = l + (r - l) / 2;
	merge_sort(A, l, m);
	merge_sort(A, m+1, r);
	merge(A, l,m,r);
}



int main(){
	int n=7;
	int a[n]={20,7,1,3,4,10,15};
	cout << "ARREGLO NO ORDENADO\n";
	print(a,n);
	merge_sort(a,0,n);
	cout << "\nARREGLO ORDENADO\n";
	print(a,n);

	return 0;
}