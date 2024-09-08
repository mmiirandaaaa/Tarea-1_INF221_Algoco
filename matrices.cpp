#include <bits/stdc++.h>
using namespace std;
using namespace chrono;

#define M 1000
#define N 1000

void poblarMatriz(vector<vector<int>> &A){
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

void mult_cubico(vector<vector<int>> &A, vector<vector<int>> &B, vector<vector<int>> &Z) {
  for (int i = 0; i < M; i++) {
    for (int j = 0; j < N; j++) {
      Z[i][j] = 0;
      for (int k = 0; k < N; k++) {
        Z[i][j] += A[i][k] * B[k][j];
      }
    }
  }
}

void mult_transpuesta(vector<vector<int>> &A, vector<vector<int>> &B, vector<vector<int>> &Z) {
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

int main(){
  srand(time(NULL));
  vector<vector<int>> A(M, vector<int>(N));
  vector<vector<int>> B(M, vector<int>(N));
  poblarMatriz(A); poblarMatriz(B);
  vector<vector<int>> C(M, vector<int>(N));
  auto start = high_resolution_clock::now();
  mult_cubico(A, B, C);
  auto end = high_resolution_clock::now();
  cout << duration_cast<seconds>(end - start).count() << '\n';
  return 0;
}