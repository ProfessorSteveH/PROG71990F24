// pointers to functions
//
// prog71990 - fall 2024 - professor steveh
//
#include <stdio.h>

int add2Ints(int a, int b)
{
	return a + b;
}

int main(void)
{
	int a = 2;
	int b = 2;

	// traditional call:
	printf("the sum is: %d\n", add2Ints(a, b));

//   +--- the return value
//   |   +--- denotes a pointer
//   |   |     +--- the name we will refer to
//   |   |     |                   +--- the parameters, in this case 2 ints
//   V   V     V                   V  V--- the address of the function to point to
	int (*functionPtr)(int, int) = &add2Ints;
	printf("the sum is: %d\n", (*functionPtr)(a, b));

	// or

	int (*anotherFunctionPtr)(int, int);
	anotherFunctionPtr = add2Ints;
	printf("the sum is: %d\n", anotherFunctionPtr(a, b));
}
