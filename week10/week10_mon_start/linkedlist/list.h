#pragma once
#include "item.h"

// prog71990-f24 - steveh - week10
// linked list interface

typedef struct listnode {
	ITEM data;
	struct listnode* next;
} LISTNODE, *PLISTNODE;

void Add(PLISTNODE* list, ITEM i);

void Remove(PLISTNODE* list, ITEM i);

void Display(PLISTNODE list);

void DestroyList(PLISTNODE* list);
