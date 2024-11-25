#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "globals.h"
#include <stdbool.h>
#include <stdio.h>

// interface for our guest ADT  (abstract data type)

// steveh - prog71990 - week11


typedef struct guest {	
	char name[MAX_NAME];  // 40
} GUEST;

//C - create
GUEST CreateGuest(char* Name);

//R - read
bool WriteGuestToStream(FILE* fp, GUEST g);
GUEST ReadGuestFromStream(FILE* fp);		// we have some technical debt here... we will return to fix!

bool CompareGuest(GUEST lhs, GUEST rhs);
GUEST CopyGuest(GUEST src);


//U - update

//D - delete
void DestroyGuest(GUEST Guest);

void PrintGuest(GUEST Guest);
