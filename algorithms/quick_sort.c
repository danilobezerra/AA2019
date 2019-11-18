#include "quick_sort.h"
#include "utils.h"

int partition(int *arr, int start, int end) {
    int pivot = arr[end];
    int i = start - 1;

    for (int j = start; j <= end - 1; j++) {
        if (arr[j] < pivot) {
            i = i + 1;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[end]);
    return i + 1;
}

int q_sort(int *arr, int start, int end) {
    if (start < end) {
        int index = partition(arr, start, end);
        q_sort(arr, start, index - 1);
        q_sort(arr, index + 1, end);
    }

    return 0;
}

int quick_sort(int *arr, int size) {
    q_sort(arr, 0, size - 1);
    return 0;
}