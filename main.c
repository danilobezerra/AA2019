#include <time.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "algorithms.h"
#include "arraygenerator.h"

int entries = 0;
void (*sort) (int *, int) = NULL;
void (*order) (int *, int) = NULL;

void run_timer() {
	clock_t t1, t2;

	for (int i = 1; i <= entries; i++) {
		int arr[i];
		int n = sizeof(arr) / sizeof(arr[0]);

    	(*order) (arr, n);

		t1 = clock();
		(*sort) (arr, n);
		t2 = clock();

		printf("%d \t %.6f\n", n, (double)(t2 - t1) / CLOCKS_PER_SEC);
	}
}

int compare(char const *a, char const *b) {
    int result = strcasecmp(a, b);
    return result == 0;
}

int main(int argc, char *argv[]) {
	if (argc < 3) { 
        printf("Falta de parâmetros. Digite --help para mais informações."); 
        return 1;
    }

	if (compare("insertion", argv[1])) {
		sort = &insertion_sort;
	} else if (compare("bubble", argv[1])) {
		sort = &bubble_sort;
	} else if (compare("selection", argv[1])) {
		sort = &selection_sort;
	} else if (compare("merge", argv[1])) {
		// TODO: sort = merge_sort;
	} else if (compare("quick", argv[1])) {
		// TODO: sort = quick_sort;
	} else if (compare("heap", argv[1])) {
		// TODO: sort = heap_sort;
	} else {
		printf("Algoritmo desconhecido. Abortando"); 
        return 1;
	}

	entries = atoi(argv[2]);

	if (compare("sorted", argv[3])) {
		order = &sorted_order;
	} else if (compare("reverse", argv[3])) {
		order = &reverse_order;
	} else if (compare("random", argv[3])) {
		order = &random_order;
	} else {
		printf("Ordem desconhecida. Abortando"); 
        return 1;
	}

	run_timer();
	return 0;
}
