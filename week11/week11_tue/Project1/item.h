#pragma once
#include <stdbool.h>

// prog71990-f24 - stevehe - week10 
// item interface

typedef struct item {
	int data;
} ITEM;

ITEM CreateItem(int i);

ITEM CopyItem(ITEM src);

bool CompareItem(ITEM lhs, ITEM rhs);

void PrintItem(ITEM i);

void DestroyItem(ITEM i);