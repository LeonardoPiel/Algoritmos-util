#ifndef SORT_H_INCLUDED
#define SORT_H_INCLUDED

int *criaVetor(int *v, int n);
int *bubbleSort(int *v, int n);
int *selectionSort(int *v, int n);
int *insertionSort(int *v, int n);
void mergeSort(int *v, int inicio, int fim);
void merge_s(int *v, int esq,int m, int dir);
void quickSOrt(int v[], int inicio, int fim);

void my_swap(int *a, int *b);
void SortPrint(int v[], int n);

void menu();

#endif // SORT_H_INCLUDED
