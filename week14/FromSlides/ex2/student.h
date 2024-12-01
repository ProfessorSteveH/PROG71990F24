#pragma once
// a fully fleshed out ADT system representing a school classroom
//
// prog71990 - fall2024 - professor steveh
//

#define _CRT_SECURE_NO_WARNINGS
#include <stdbool.h>
#include <stdio.h>

#define STUDENTLEN 50
#define MAXBUFFER	80

typedef struct student
{
	char name[STUDENTLEN];
	int studentnum;
} STUDENT;

STUDENT createStudent(char[], int);
void printStudent(STUDENT);
bool writeStudentToStream(FILE*, STUDENT);
STUDENT readStudentFromStream(FILE*);

bool compareStudents(STUDENT, STUDENT);
STUDENT copyStudent(STUDENT);

void disposeStudent(STUDENT);

