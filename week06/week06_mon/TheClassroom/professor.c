#define _CRT_SECURE_NO_WARNINGS

#include "professor.h"
#include <stdio.h>
#include <string.h>

// prog71990-f24 - week06 - steveh

//C - create
PROFESSOR CreateProfessor(char Name[], char Dept[]) {
	PROFESSOR newProfessor;

	strncpy(newProfessor.name, Name, NAME_LENGTH);
	strncpy(newProfessor.dept, Dept, DEPT_LENGTH);

	return newProfessor;
}

//R - read


//U - update


//D - delete
void DestroyProfessor(PROFESSOR Professor) {
	// in this implementation, nothing to be done
}

void PrintProfessor(PROFESSOR Professor) {
	printf("PROFESSOR: %s, %s\n", Professor.name, Professor.dept);
}