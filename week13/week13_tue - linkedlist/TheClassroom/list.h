#pragma once
#include "participant.h"
#include <stdbool.h>

// prog71990-f24 - steveh - week10
// list interface

typedef struct listnode {
	PARTICIPANT data;
	struct listnode* next;
} LISTNODE, *PLISTNODE;

bool Add(PLISTNODE* list, PARTICIPANT p);

bool Remove(PLISTNODE* list, PARTICIPANT p);

int GetListCount(PLISTNODE list);

void Clear(PLISTNODE* list);

void Display(PLISTNODE list);

bool WriteListToStream(PLISTNODE list, FILE* fp);

/// <summary>
/// Removes and invalidates the list.  The list is left in an unknown/unsafe state at the end of this call.
/// </summary>
/// <param name="list"></param>
void Destroy(PLISTNODE* list);