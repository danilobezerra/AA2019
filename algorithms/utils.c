#include "utils.h"
#include <string.h>
#include <stdlib.h>

void swap(int *item_a, int *item_b) {
    int temp = *item_a;
    *item_a = *item_b;
    *item_b = temp;
}

int compare(char const *str_a, char const *str_b) {
    int result = strcasecmp(str_a, str_b);
    return result == 0;
}

void random_order(int *buf, int count) {
    for (int i = 0; i < count; ++i) {
		buf[i] = rand();
	} 
}

void sorted_order(int *buf, int count) {
    for (int i = 0; i < count; ++i) {
		buf[i] = i;
	} 
}

void reverse_order(int *buf, int count) {
    for (int i = 0; i < count; ++i) {
		buf[count - i - 1] = i;
	} 
}