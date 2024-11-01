#pragma once
#include <stdio.h>
#include <stdlib.h>

// declaration/definition of list 2

// PROG71990F24 - Nov 2024 - Professor SteveH

// revision history
//      1.0      2020-Jun-28          initial
//      1.1      2021-Jun-24          reviewed and updated
//      1.2     2022-May-20         reviewed
//		1.3		  2023-Jul-19		reviewed
//		1.4		  2024-Aug-25		reviewed

typedef struct listnode
{
	int info;
	struct listnode* next;
}LISTNODE, * PLISTNODE;

void Display(PLISTNODE);

void addItem(PLISTNODE*, int);
void removeItem(PLISTNODE*, int);

