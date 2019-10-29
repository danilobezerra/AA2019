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
long int* setupBubbleSort(long int n, char mode) 
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
long int* setupSelectionSort(long int n, char mode) 
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
void BubbleSort(long int n, long int* v)
{
    for(int i = n-1; i >= 0; i--)
    {
        for(int j = 0; j < i; j++) 
        {
            if(v[j] > v[j+1]) 
            {
                int x = v[j];
                v[j] = v[j+1];
                v[j+1] = x;
            }
        }
    }
}
void SelectionSort(long int n, long int* v)
{
    for(int i = 0; i < n; i++) 
    {
        int min = i;
        for(int j = i + 1; j < n; j++)
        {
            if(v[j] < v[min])
            {
                min = j;
            }
        }
        int x = v[i];
        v[i] = v[min];
        v[min] = x;
    }
}
// void MergeSort();
// void QuickSort();
// void HeapSort();

