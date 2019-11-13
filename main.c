#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#include "algorithms/insertion_sort.h"
#include "algorithms/bubble_sort.h"
#include "algorithms/selection_sort.h"
#include "algorithms/merge_sort.h"
#include "algorithms/quick_sort.h"
#include "algorithms/heap_sort.h"

#include "algorithms/utils.h"

int (*algorithm) (int *, int) = NULL;
void (*order) (int *, int) = NULL;

// ./sort algorithm order entries step
void run_timer(int entries, int step) {
    clock_t t1, t2;

    for (int i = 0; i <= entries; i += step) {
        if (i == 0) continue;

        int arr[i];
        int n = sizeof(arr) / sizeof(arr[0]);

        (*order) (arr, n);

        t1 = clock();
        (*algorithm) (arr, n);
        t2 = clock();

        printf("%d \t %.6f\n", n, (double)(t2 - t1) / CLOCKS_PER_SEC);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Falta de parâmetros. Digite --help para mais informações.\n");
        return 1;
    }

    if (compare("insertion", argv[1])) {
        algorithm = &insertion_sort;
    } else if (compare("bubble", argv[1])) {
        algorithm = &bubble_sort;
    } else if (compare("selection", argv[1])) {
        algorithm = &selection_sort;
    } else if (compare("merge", argv[1])) {
        algorithm = &merge_sort;
    } else if (compare("quick", argv[1])) {
        algorithm = &quick_sort;
    } else if (compare("heap", argv[1])) {
        algorithm = &heap_sort;
    } else {
        printf("Algoritmo desconhecido. Abortando");
        return 1;
    }

    if (compare("sorted", argv[2])) {
        order = &sorted_order;
    } else if (compare("reverse", argv[2])) {
        order = &reverse_order;
    } else if (compare("random", argv[2])) {
        order = &random_order;
    } else {
        printf("Ordem desconhecida. Abortando");
        return 1;
    }

    int entries = 1000;
    if (argc > 3 && argv[3] != NULL) {
        entries = atoi(argv[3]);
    }

    int step = 1;
    if (argc > 4 && argv[4] != NULL) {
        step = atoi(argv[4]);
    }

    run_timer(entries, step);
    return 0;
}