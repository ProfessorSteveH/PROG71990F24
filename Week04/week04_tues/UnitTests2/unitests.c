#include "unitests.h"

// prog71990-f24 - steveh - week04
// implementation of unit tests

bool run_test(int inA, int inB) {
	int expectedA = inB;
	int expectedB = inA;

	swap(&inA, &inB);
	if (inA == expectedA && inB == expectedB)
		return true;
	else
		return false;
}