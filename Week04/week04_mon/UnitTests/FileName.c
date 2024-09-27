#include <stdio.h>

// test harness for utils library

// steveh - prog71990f24 - week04

int main(void) {

	printf("test 01: ");
	if (testUnit(1, 2, 3, 3))
		printf("passed\n");
	else
		printf("failed\n");

	printf("test 02: ");
	if (testUnit(-1, 0, 1, 1))
		printf("passed\n");
	else
		printf("failed\n");

	printf("test 03: ");
	if (testUnit(1, -1, 0, 1))
		printf("passed\n");
	else
		printf("failed\n");

	return 0;
}