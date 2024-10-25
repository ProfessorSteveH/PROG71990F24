#pragma once

#define NAME_LENGTH		40
#define DEPT_LENGTH		40

// prog71990-f24 - week06 - steveh

typedef struct professor {		// size_t size = sizeof(PROFESSOR);
	char name[NAME_LENGTH];		// size = 80
	char dept[DEPT_LENGTH];
} PROFESSOR;

//C - create
PROFESSOR CreateProfessor(char Name[], char Dept[]);

//R - read


//U - update


//D - delete
void DestroyProfessor(PROFESSOR Professor);

void PrintProfessor(PROFESSOR Professor);