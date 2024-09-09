#ifndef ORDENAMIENTO_H
#define ORDENAMIENTO_H

#include "Ordenamiento.h"

void PrintArr(int *arr, int n);
void InsertionSort(int *arr, int n);
void merge(int *A, int l, int m, int r);
void MergeSort(int *A, int l, int r);
int particion(int *A, int l, int r);
void QuickSort(int *A, int l, int r);

#endif