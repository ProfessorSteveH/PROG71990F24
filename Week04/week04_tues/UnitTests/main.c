#include <stdio.h>
#include "unittests.h"
// steveh - prog71990f24 - week04

// unit tests for utils library

int main(void) {

	printf("test01: ");		// inputs  //expected
	bool result = run_my_test(1, 2, 3, 3);
	if (result)
		printf("passed\n");
	else
		printf("failed\n");
	
	printf("test02: ");		// inputs  //expected
	result = run_my_test(-1, -2, 0, 0);
	if (result)
		printf("passed\n");
	else
		printf("failed\n");

	return 0;
}