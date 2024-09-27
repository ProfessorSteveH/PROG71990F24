#include <stdio.h>

// write a program that tests a function (that you will write, in a
// separate component (the combination of .h and .c file)) 
// that takes 2 ints as parameters and swaps them
// a = 1; b = 2;
// run function
// b = 1; a = 2;
// and create properly structured unit tests for the function.

// steveh - prog71990f24 - week04

// this is an example of 
// 'pass by value'
// and
// 'pass by reference'

// & => ' the address of ...'
// * => ' the value at ...' 

int main(void) {

	int a = 1;

	int b = 2;
	printf("a=%d, b=%d\n", a, b);
	swap(&a,&b);
	printf("a=%d, b=%d\n", a, b);

	return 0;
}