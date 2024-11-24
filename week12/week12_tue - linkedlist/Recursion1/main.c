#include <stdio.h>
#include <stdlib.h>



// prog71990-f24 - week12 - steveh
// intro to recursion

// recursion is a technique of solving a problem by iteratively
// solving a smaller/easier problem
 
// eg:  factorial  !
// 4! = 4 * 3 * 2 * 1  			we define 0! = 1
//    = 4 * 3!
//          3 * 2!
//              2 * 1!

int factorial(int number) {
	// a when using factorial, we consider 2 cases:
	//   a. recursive step  (repeated many times over)
	//   b. base or exit condition (how do we know we are done)

	if (number < 0) {
		fprintf(stderr, "factorial-izing a negative number is not allowed\n");
		exit(EXIT_FAILURE);
	}

	if (number == 0)
		return 1;
	else
		return (number * factorial(number - 1));
}

int loopfactorial(int number) {	// this is not recursive, but
							// totally acceptable
	if (number < 0) {
		fprintf(stderr, "factorial-izing a negative number is not allowed\n");
		exit(EXIT_FAILURE);
	}
	int total = number;		// 4
	for (int i = 1; i < number; i++)
		total *= i;			// 4 * 1 * 2 * 3

	return total;
}


int main(void) {

	printf("%d\n", factorial(4));

	return 0;
}
					