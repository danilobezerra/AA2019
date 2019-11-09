#include "algorithms.h"

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void insertion_sort(int *arr, int size) {
    for (int i = 1; i < size; i++) {
		int key = arr[i];
		int j = i - 1;

		while (j >= 0 && arr[j] > key) {
			arr[j + 1] = arr[j];
			j = j - 1;
		}

		arr[j + 1] = key;
	}
}

void bubble_sort(int *arr, int size) {
    for (int i = (size - 1); i >= 0; i--) {
		for (int j = 0; j < i; j++) {
			if (arr[j] > arr[j + 1]) {
				swap(&arr[j], &arr[j + 1]);
			}
		}
	}
}

void selection_sort(int *arr, int size) {
    for (int i = 0; i < (size - 1); i++) {
		int min_index = i;
		
		for (int j = (i + 1); j < size; j++) {
			if (arr[j] < arr[min_index]) {
				min_index = j;
			}
		}

		swap(&arr[i], &arr[min_index]);
	}
}

// TODO: void merge_sort(int *arr, int n);
// TODO: void quick_sort(int *arr, int n);
// TODO: void heap_sort(int *arr, int n);