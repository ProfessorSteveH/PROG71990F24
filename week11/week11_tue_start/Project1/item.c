#include "item.h"
#include <stdio.h>

// prog71990-f24 - steveh - week10
// item impl.

ITEM CreateItem(int i) {
	ITEM I;
	I.data = i;
	return I;
}

ITEM CopyItem(ITEM src) {
	return CreateItem(src.data);
}

bool CompareItem(ITEM lhs, ITEM rhs) {
	return (lhs.data == rhs.data);
}

void PrintItem(ITEM i) {
	printf("ITEM: %d\n", i.data);
}

void DestroyItem(ITEM i) {
	// nothing
}