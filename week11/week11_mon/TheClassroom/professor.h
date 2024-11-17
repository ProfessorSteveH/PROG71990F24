#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "globals.h"
#include <stdbool.h>
#include <stdio.h>


// prog71990-f24 - week10 - steveh

typedef struct professor {		// size_t size = sizeof(PROFESSOR);
	char name[MAX_NAME];		// size = 80
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