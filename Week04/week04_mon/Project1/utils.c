#include "utils.h"
#include <stdio.h>

// implementation of our utils library

// steveh - prog71990f24 - week04


//			these a,b,c are a separate copy of the a,b,c in main
int max_of_3_ints(int a, int b, int c) {
	int max = a;

	if (b > max)
		max = b;

	if (c > max)
		max = c;

	return max;
	// the local a,b,c are discarded (changed or not)
}

void print_output_line(int a, int b, int c, int max) {
	printf("the max of %d,%d,%d is %d\n", a, b, c, max);
}