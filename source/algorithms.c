#include "algorithms.h"
#include "arraygenerator.h"

long int *setupInsertionSort(long int n, char mode)
{
    switch (mode)
    {
        case BEST:
            return increascingOrder(n);
            break;
        case AVERAGE:
            return randomOrder(n);
            break;
        case WORST:
            return decreascingOrder(n);
            break;
    }
}
// long int* setupBubbleSort(long int n, char mode) {}
// long int* setupSelectionSort(long int n, char mode) {}
// long int* setupMergeSort(long int n, char mode) {}
// long int* setupQuickSort(long int n, char mode) {}
// long int* setupHeapSort(long int n, char mode) {}
void InsertionSort(long int n, long int* v) 
{
    for(int i = 1; i < n; i++) 
    {
        long int x = v[i];
        int j = i-1;
        while(j >= 0 && v[j] > x) 
        {
            
            v[j+1] = v[j];
            j = j-1;
        }
        v[j+1] = x;
    }
}
// void BubbleSort();
// void SelectionSort();
// void MergeSort();
// void QuickSort();
// void HeapSort();

