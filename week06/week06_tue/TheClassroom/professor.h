#pragma once

// interface for our new professor ADT (abstract data type)

// steveh - prog71990-f24 - week05

#define NAME_MAX_SIZE	60
#define DEPT_MAX_SIZE	60

	// structs work on the principle of AND (attrib1 AND attrib2 AND ... )
typedef struct professor {			// sizeof(PROFESSOR) = 120 
	char name[NAME_MAX_SIZE];
	char dept[DEPT_MAX_SIZE];
} PROFESSOR;

//C - create
PROFESSOR CreateProfessor(char Name[], char Dept[]);

//R - read

//U - update

//D - delete
void DestroyProfessor(PROFESSOR Professor);


void PrintProfessor(PROFESSOR Professor);

