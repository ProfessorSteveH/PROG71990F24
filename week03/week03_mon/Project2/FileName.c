// write an program to find the max of 3 numbers, 
// output stored in variable named max

// steveh - prog71990-f24 - week03

#include <stdio.h>

int main(void) {

	//input
	int a = 1;
	int b = 2;
	int c = 3;

	//transform

	int max = a;

	if (b > max) 
		max = b;

	if (c > max)
		max = c;


	//output
	printf("the max of %d,%d,%d is %d\n", a, b, c, max);
	return 0;
}