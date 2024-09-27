// write a function that swaps two integers...
// eg: 
// swap(int a, int b)
// eg:  if a=1, b=2
// before the call a=1, b=2
// after the call  a=2, b=1
// 
// follow up with proper unit test

#include <stdio.h>

// steveh - prog71990f24 - week04

int main(void) {

	int a = 1;
	int b = 2;
	printf("before: a=%d b=%d\n", a, b);
	//swap(a, b);	// pass by value

	// & => ' the address of '
	swap(&a, &b); // pass by reference

	printf(" after: a=%d b=%d\n", a, b);
	return 0;
}