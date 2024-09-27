#include "unittests.h"
#include "../Project1/utils.h"
#include <stdio.h>

// steveh - prog71990 - week04

// unittests implementation

bool run_my_test(int inA, int inB, int inC, int expected) {

	int actual = largest_of_three_ints(inA, inB, inC);
	if (actual == expected)			//assert_equal(expected, actual);
		return true;
	else
		return false;
}