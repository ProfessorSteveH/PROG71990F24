#include "utils.h"
#include <stdio.h>

// prog71990-f24 - ssteveh - week04
// implementation of library functions

void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}