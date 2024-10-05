#define _CRT_SECURE_NO_WARNINGS
#include "student.h"
#include <string.h>
#include <stdio.h>

//prog71900-f24 - steveh - week05

// student implementation

//C - create
STUDENT CreateStudent(char Name[], int StudentNumber) {
	STUDENT newStudent;

	strncpy(newStudent.name, Name, NAME_MAX_SIZE);
	newStudent.studentNum = StudentNumber;

	return newStudent;
}

//R - read

//U - update

//D - delete
void DestroyStudent(STUDENT Student) {
	// either set attributes to null or
	// do nothing.
}

void PrintStudent(STUDENT Student) {
	printf("STUDENT: %s, %d\n", Student.name, Student.studentNum);
}