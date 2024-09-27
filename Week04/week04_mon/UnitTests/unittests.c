#include "unittests.h"
#include "utils.h"
#include <stdio.h>


// implementation of unittest framework

// steveh = prog71990f24 - week04

bool testUnit(int inA, int inB, int inC, int expected) {
	int actual = max_of_3_ints(inA, inB, inC);
	if (actual == expected)
		return true;
	else
		return false;
}