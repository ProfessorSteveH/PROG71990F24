#pragma once
#include <stdbool.h>

// prog71990-f24 - steveh - week10
// item interface

typedef struct item {
	int value;
} ITEM;

ITEM CreateItem(int i);

bool CompareItem(ITEM lhs, ITEM rhs);

ITEM CopyItem(ITEM src);

void PrintItem(ITEM i);

void DestroyItem(ITEM i);

