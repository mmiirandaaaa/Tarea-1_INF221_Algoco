#include <bits/stdc++.h>
#include "Matrices.h"
using namespace std;

void PoblarMatriz(vector<vector<int>> &A){
  for(int i = 0; i<M; i++){
    for(int j = 0; j<N; j++){
      A[i][j] = rand() % 10 + 1;
    }
  } 
}

void print(vector<vector<int>> &A) {
  for (int i = 0; i < M; i++) {
    cout << "|";
    for (int j = 0; j < N; j++) {
      cout << " " << A[i][j];
    }
    cout << " |\n";
  }
}

void MultCubico(vector<vector<int>> &A, vector<vector<int>> &B, vector<vector<int>> &Z) {
  for (int i = 0; i < M; i++) {
    for (int j = 0; j < N; j++) {
      Z[i][j] = 0;
      for (int k = 0; k < N; k++) {
        Z[i][j] += A[i][k] * B[k][j];
      }
    }
  }
}

void MultTranspuesta(vector<vector<int>> &A, vector<vector<int>> &B, vector<vector<int>> &Z) {
  vector<vector<int>> B_T(M, vector<int>(N));
  for (int i = 0; i < M; i++) {
    for (int j = 0; j < N; j++) {
      B_T[j][i] = B[i][j];
    }
  }

  for (int i = 0; i < M; i++) {
    for (int j = 0; j < N; j++) {
      Z[i][j] = 0;
      for (int k = 0; k < M; k++) {
        Z[i][j] += A[i][k] * B[j][k];
      }
    }
  }
}