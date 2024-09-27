// write an program to find the max of 3 numbers, 
// output stored in variable named max

// steveh - prog71990-f24 - week03

#include "utils.h"
#include <stdio.h>


int main(void) {

	//input
	int a = 1;  // -1; // 1;
	int b = -1; // 0;  // 2;
	int c = 0;  // 1;  // 3;

	//transform
	int max = max_of_3_ints(a, b, c);

	//output
	print_output_line(a, b, c, max);
	
	return 0;
}
