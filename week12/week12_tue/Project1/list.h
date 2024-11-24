#pragma once
#include "item.h"

// prog71990-f24 - steveh - week10
// list interface

typedef struct listnode {
	ITEM data;
	struct listnode* next;
} LISTNODE, *PLISTNODE;

void Add(PLISTNODE* list, ITEM i);

void Remove(PLISTNODE* list, ITEM i);

void Clear(PLISTNODE* list);

void Display(PLISTNODE list);

/// <summary>
/// Removes and invalidates the list.  The list is left in an unknown/unsafe state at the end of this call.
/// </summary>
/// <param name="list"></param>
void Destroy(PLISTNODE* list);