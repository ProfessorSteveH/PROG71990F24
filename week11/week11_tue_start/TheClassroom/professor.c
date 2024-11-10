#define _CRT_SECURE_NO_WARNINGS
#include "globals.h"
#include "professor.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

// prog71990-f24 - steveh - week10

// professor implementation

//C - create
PROFESSOR CreateProfessor(char Name[], char Dept[]) {
	PROFESSOR newProfessor;

	strncpy(newProfessor.name, Name, MAX_NAME);
	strncpy(newProfessor.dept, Dept, MAX_DEPT);

	return newProfessor;
}

//R - read
bool WriteProfessorToStream(FILE* fp, PROFESSOR p) {

	fprintf(fp, "%s\n", p.name);
	fprintf(fp, "%s\n", p.dept);

	return true;
}

PROFESSOR ReadProfessorFromStream(FILE* fp) {

	char tempBuffer[MAX_NAME] = { 0 };
	char* result = fgets(tempBuffer, MAX_NAME, fp);
	if (result == NULL) {  // bad things happened
		fprintf(stderr, "error, not able to read name from file\n");
		exit(EXIT_FAILURE);
	}
	char tempBuffer2[MAX_DEPT] = { 0 };
	result = fgets(tempBuffer2, MAX_DEPT, fp);
	if (result == NULL) {  // bad things happened
		fprintf(stderr, "error, not able to read dept from file\n");
		exit(EXIT_FAILURE);
	}

	return CreateProfessor(tempBuffer, tempBuffer2);
}


bool CompareProfessors(PROFESSOR lhs, PROFESSOR rhs) {
	int nameDiff = strcmp(lhs.name, rhs.name);
	if (nameDiff != 0)
		return false;

	int deptDiff = strcmp(lhs.dept, rhs.dept);
	if (deptDiff != 0)
		return false;

	return true;
}


//U - update

//D - delete
void DestroyProfessor(PROFESSOR Professor) {
	// not necessary in this implementation
}


void PrintProfessor(PROFESSOR Professor) {
	printf("PROFESSOR: %s, %s\n", Professor.name, Professor.dept);
}