#include <stdlib.h>
#include "arraygenerator.h"

void random_order(long int *buf, int count) {
    for (int i = 0; i < count; ++i) {
		buf[i] = rand();
	} 
}

void ascending_order(long int *buf, int count) {
    for (int i = 0; i < count; ++i) {
		buf[i] = i;
	} 
}

void descending_order(long int *buf, int count) {
    for (int i = 0; i < count; ++i) {
		buf[count - i - 1] = i;
	} 
}
