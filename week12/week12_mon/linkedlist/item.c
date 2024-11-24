#include "item.h"
#include <stdio.h>

// prog71990-f24 - steveh - week10
// item impl

ITEM CreateItem(int i) {
	ITEM I;
	I.value = i;
	return I;
}

bool CompareItem(ITEM lhs, ITEM rhs) {
	return (lhs.value == rhs.value);
}

ITEM CopyItem(ITEM src) {
	return CreateItem(src.value);
}

void PrintItem(ITEM i) {
	printf("ITEM: %d\n", i.value);
}

void DestroyItem(ITEM i) {
	//nothing
}