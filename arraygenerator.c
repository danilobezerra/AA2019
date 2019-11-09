#include <stdlib.h>
#include "arraygenerator.h"

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
