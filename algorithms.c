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

void merge(int *arr, int start, int middle, int end) {
	int n1 = middle - start + 1;
	int n2 = end - middle;

	int arr_left[n1], arr_right[n2];

	for (int i = 0; i < n1; i++) {
		arr_left[i] = arr[start + i];
	}

	for (int j = 0; j < n2; j++) {
		arr_right[j] = arr[middle + (j + 1)];
	}

	int i = 0, j = 0, k = start;

	while (i < n1 && j < n2) {
		if (arr_left[i] <= arr_right[j]) {
			arr[k] = arr_left[i];
			i = i + 1;
		} else {
			arr[k] = arr_right[j];
			j = j + 1;
		}

		k = k + 1;
	}

	while (i < n1) {
		arr[k] = arr_left[i];
		i = i + 1;
		k = k + 1;
	}

	while (j < n2) {
		arr[k] = arr_right[j];
		j = j + 1;
		k = k + 1;
	}
}

void _merge_sort(int *arr, int start, int end) {
	if (start < end) {
		int middle = (start + end) / 2;

		_merge_sort(arr, start, middle);
		_merge_sort(arr, middle + 1, end);

		merge(arr, start, middle, end);
	}
}

void merge_sort(int *arr, int size) {
	_merge_sort(arr, 0, size - 1);
}

// TODO: void quick_sort(int *arr, int n);
// TODO: void heap_sort(int *arr, int n);