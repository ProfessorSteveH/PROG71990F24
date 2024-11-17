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

void Empty(PLISTNODE* list);

/// <summary>
/// This function destroys the list.  The list is in an unknown state after this call returns
/// </summary>
/// <param name="list"></param>
void DestroyList(PLISTNODE* list);
