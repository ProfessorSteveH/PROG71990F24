#include <stdio.h>

//prog71990-f24 - steveh - week12
// recursion 0

// recursion solve as problem using a loop/iteration of a 
// simpler version of the problem

// factorial   4! = 4 * 3 * 2 * 1 * 0     // 0! = 1
//                = 4 * 1 * 2 * 3
//				4! = 4 * 3!
//                       3! = 3 * 2!
//                                2 * 1!
//                                    1 * 0!
//                                        1
//              x:xs
//              [ 4, 3, 2, 1, 0 ]
//
// when considering solving a problem using recursion, 
// consider 2 cases:
//  a. recursive step
//  b. exit condition

// reasons to consider using iterative over recursive solution:
// 1. performance (creating stack frame is expensive)
// 2. stack overflow (stack maxes out at 1Mb)
// 3. for some recursive code is harder to write/read

int factorial(int number) {
	if (number == 0)
		return 1;
	else
		return (number * factorial(number - 1));
}

int loopfactorial(int number) {				// iterative solution
	int total = number;
	for (int i = 1; i < number; i++)
		total *= i;
	return total;
}

int main(void) {

	printf("%d\n", factorial(4));

	return 0;
}