#ifndef ORDENAMIENTO_H
#define ORDENAMIENTO_H

#include <bits/stdc++.h>
#include "Ordenamiento.h"

void PrintArr(std::vector<int> &arr, int n);
void InsertionSort(std::vector<int> &arr, int n);
void merge(std::vector<int> &A, int l, int m, int r);
void MergeSort(std::vector<int> &A, int l, int r);
int particion(std::vector<int> &A, int l, int r);
void QuickSort(std::vector<int> &A, int l, int r);

#endif