#include "algorithms.h"

void insertion_sort(long int* arr, long int n)
{
	for (int i = 1; i < n; i++) {
        long int x = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > x) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = x;
    }
}

void bubble_sort(long int* arr, long int n)
{
    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j < i; j++) {
            if (arr[j] > arr[j + 1]) {
                int x = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = x;
            }
        }
    }
}
void selection_sort(long int* arr, long int n)
{
    for (int i = 0; i < n; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min]) {
                min = j;
            }
        }
        int x = arr[i];
        arr[i] = arr[min];
        arr[min] = x;
    }
}

// TODO: void merge_sort();
// TODO: void quick_sort();
// TODO: void heap_sort();

