#include <stdlib.h>
#include <stdio.h>

#define BEST 'b'
#define AVERAGE 'a'
#define WORST 'w'

/** Descrição **/
/*
* Funções usadas para criar o vetor e aplciar outras configurações
* antes da ordenação em si.
*/
long int* setupInsertionSort(long int,char);
long int* setupBubbleSort(long int,char);
long int* setupSelectionSort(long int,char);
long int* setupMergeSort(long int,char);
long int* setupQuickSort(long int,char);
long int* setupHeapSort(long int,char);
/** TO DO (Menos IsnertioN) **/
void InsertionSort(long int, long int*);
void BubbleSort();
void SelectionSort();
void MergeSort();
void QuickSort();
void HeapSort();
