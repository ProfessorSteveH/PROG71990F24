#include "utils.h"
#include <stdio.h>

// prg71990-f24 - steveh - week04
// implementation of utility functions

//  * => 'the value at ...'

void swap(int* a, int* b) {  //a and b are addresses
	int temp = *a;
	*a = *b;
	*b = temp;
}