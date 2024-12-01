#pragma once
#include "participant.h"
#include <stdbool.h>

// prog71990-f24 - steveh - week10
// linked list interface

typedef struct listnode {
	PARTICIPANT data;
	struct listnode* next;
} LISTNODE, *PLISTNODE;

bool Add(PLISTNODE* list, PARTICIPANT p);

bool Remove(PLISTNODE* list, PARTICIPANT p);

void Display(PLISTNODE list);
bool WriteListToStream(PLISTNODE list, FILE* fp);

int GetCountOfParticipants(PLISTNODE list);

void Empty(PLISTNODE* list);

/// <summary>
/// This function destroys the list.  The list is in an unknown state after this call returns
/// </summary>
/// <param name="list"></param>
void DestroyList(PLISTNODE* list);
