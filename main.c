#include <time.h>
#include <math.h>
#include <stdio.h>

#include "algorithms.h"
#include "arraygenerator.h"

int main(void) {
    clock_t t1, t2;

	for (int i = 0; i < 9; i++) {
		long int arr[1000 * (int)pow(2, i)];
		long int n = sizeof(arr) / sizeof(arr[0]);

    	descending_order(arr, n);

		t1 = clock();
		selection_sort(arr, n);
		t2 = clock();

        printf("%ld \t %.6f\n", n, (double)(t2 - t1) / CLOCKS_PER_SEC);
	}
	
	return 0;
}