#include "heap_sort.h"
#include "utils.h"

int max_heapify(int *arr, int size, int node) {
    int largest = node;
    int left = 2 * node + 1;
    int right = 2 * node + 2;

    if (left < size && arr[left] > arr[largest]) {
        largest = left;
    }

    if (right < size && arr[right] > arr[largest]) {
        largest = right;
    }

    if (largest != node) {
        swap(&arr[node], &arr[largest]);
        max_heapify(arr, size, largest);
    }

    return 0;
}

int heap_sort(int *arr, int size) {
    for (int i = (size / 2 - 1); i >= 0; i--) {
        max_heapify(arr, size, i);
    }
    
    for (int i = (size - 1); i >= 0; i--) {
        swap(&arr[0], &arr[i]);
        max_heapify(arr, i, 0);
    }

    return 0;
}