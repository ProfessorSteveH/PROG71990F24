#include "unittests.h"
#include "utils.h"
#include <stdio.h>

// prog71990-f24 - week04 - steveh 
// implementation of swap tests

bool testrunner(int inA, int inB) {
	
	int expectedA = inB;
	int expectedB = inA;
	swap(inA, inB);

	if(expectedA == inA && expectedB == inB)
		return true;
	else
		return false;
}