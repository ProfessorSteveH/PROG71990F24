#pragma once
#include "globals.h"
#include <stdbool.h>
#include <stdio.h>

// interface for our new professor ADT (abstract data type)

// steveh - prog71990-f24 - week10


	// structs work on the principle of AND (attrib1 AND attrib2 AND ... )
typedef struct professor {			// sizeof(PROFESSOR) = 120 
	char name[MAX_NAME];
	char dept[MAX_DEPT];
} PROFESSOR;

//C - create
PROFESSOR CreateProfessor(char Name[], char Dept[]);

//R - read
bool WriteProfessorToStream(FILE* fp, PROFESSOR p);
PROFESSOR ReadProfessorFromStream(FILE* fp);		// we have some technical debt here... we will return to fix!

bool CompareProfessors(PROFESSOR lhs, PROFESSOR rhs);

//U - update

//D - delete
void DestroyProfessor(PROFESSOR Professor);


void PrintProfessor(PROFESSOR Professor);

