#include "merge_sort.h"

int merge(int *arr, int start, int middle, int end) {
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

    return 0;
}

int sort(int *arr, int start, int end) {
	if (start < end) {
		int middle = (start + end) / 2;

		sort(arr, start, middle);
		sort(arr, middle + 1, end);

		merge(arr, start, middle, end);
	}

    return 0;
}

int merge_sort(int *arr, int size) {
    sort(arr, 0, size - 1);
    return 0;
}