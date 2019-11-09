#include "algorithms.h"

void swap(int *a, int *b) { 
    int temp = *a; 
    *a = *b; 
    *b = temp; 
} 

void insertion_sort(int *arr, int n)
{
	for (int i = 1; i < n; i++) {
        int x = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > x) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = x;
    }
}

void bubble_sort(int *arr, int n)
{
    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j < i; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}
void selection_sort(int *arr, int n)
{
    for (int i = 0; i < n; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min]) {
                min = j;
            }
        }
        swap(&arr[i], &arr[min]);
    }
}

// TODO: void merge_sort(int *arr, int n);
// TODO: void quick_sort(int *arr, int n);
// TODO: void heap_sort(int *arr, int n);

