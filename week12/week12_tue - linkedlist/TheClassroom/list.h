#pragma once
#include "participant.h"

// prog71990-f24 - steveh - week10
// list interface

typedef struct listnode {
	PARTICIPANT data;
	struct listnode* next;
} LISTNODE, *PLISTNODE;

void Add(PLISTNODE* list, PARTICIPANT p);

void Remove(PLISTNODE* list, PARTICIPANT p);

void Clear(PLISTNODE* list);

void Display(PLISTNODE list);

/// <summary>
/// Removes and invalidates the list.  The list is left in an unknown/unsafe state at the end of this call.
/// </summary>
/// <param name="list"></param>
void Destroy(PLISTNODE* list);