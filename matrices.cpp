#include <bits/stdc++.h>
#include "Matrices.h"
using namespace std;

void PoblarMatriz(vector<vector<int>> &A){
  int M = A.size(); int N = A[0].size();
  for(int i = 0; i<M; i++){
    for(int j = 0; j<N; j++){
      A[i][j] = rand() % 10 + 1;
    }
  } 
}

void print(vector<vector<int>> &A){
  int M = A.size(); int N = A[0].size();
  for (int i = 0; i < M; i++){
    cout << "|";
    for (int j = 0; j < N; j++){
      if(A[i][j] >= 10){
        cout << " " << A[i][j];
      }
      else{
        cout << "  " << A[i][j];
      }
    }
    cout << " |\n";
  }
}

void MultCubico(vector<vector<int>> &A, vector<vector<int>> &B, vector<vector<int>> &Z) {
  int M = A.size(); int N = A[0].size();
  int L = B.size(); int R = B[0].size();
  if(N==L){
    for(int i = 0; i < M; i++){
      for(int j = 0; j < R; j++){
        Z[i][j] = 0;
        for(int k = 0; k < N; k++){
          Z[i][j] += A[i][k] * B[k][j];
        }
      }
    }
  }
  else{
    cout << "No se puede realizar la multiplicación\n";
  }
}

void MultTranspuesta(vector<vector<int>> &A, vector<vector<int>> &B, vector<vector<int>> &Z) {
  int M = A.size(); int N = A[0].size();
  int L = B.size(); int R = B[0].size();
  if(N==L){
    vector<vector<int>> B_T(R, vector<int>(L));
    for (int i = 0; i < L; i++) {
      for (int j = 0; j < R; j++) {
        B_T[j][i] = B[i][j];
      }
    }

    for (int i = 0; i < M; i++) {
      for (int j = 0; j < R; j++) {
        Z[i][j] = 0;
        for (int k = 0; k < N; k++) {
          Z[i][j] += A[i][k] * B_T[j][k];
        }
      }
    }
  }
  else{
    cout << "No se puede realizar la multiplicación\n";
  }
}