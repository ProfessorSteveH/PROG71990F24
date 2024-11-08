#define _CRT_SECURE_NO_WARNINGS
#include "professor.h"
#include <stdio.h>
#include <string.h>

// prog71990-f24 - steveh - week10

// professor implementation

//C - create
PROFESSOR CreateProfessor(char Name[], char Dept[]) {
	PROFESSOR newProfessor;

	strncpy(newProfessor.name, Name, NAME_MAX_SIZE);
	strncpy(newProfessor.dept, Dept, DEPT_MAX_SIZE);

	return newProfessor;
}

//R - read

//U - update

//D - delete
void DestroyProfessor(PROFESSOR Professor) {
	// not necessary in this implementation
}


void PrintProfessor(PROFESSOR Professor) {
	printf("PROFESSOR: %s, %s\n", Professor.name, Professor.dept);
}