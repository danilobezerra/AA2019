#include "bubble_sort.h"
#include "utils.h"

int bubble_sort(int *arr, int size) {
    for (int i = (size - 1); i >= 0; i--) {
		for (int j = 0; j < i; j++) {
			if (arr[j] > arr[j + 1]) {
				swap(&arr[j], &arr[j + 1]);
			}
		}
	}
    
    return 0;
}