#include "utils.h"
#include <stdio.h>

// steveh - prog71990 - week04

// utils library implementation 


int largest_of_three_ints(int inputOne, int inputTwo, int inputThree) {
	int max = inputOne;
	if (inputTwo > max)
		max = inputTwo;
	if (inputThree > max)
		max = inputThree;

	return max;
}
void printOutput(int a, int b, int c, int max) {
	printf("the max of %d,%d,%d is %d\n", a, b, c, max);
}