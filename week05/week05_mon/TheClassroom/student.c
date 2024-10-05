#define _CRT_SECURE_NO_WARNINGS

#include "student.h"
#include <stdio.h>
#include <string.h>

// prog71990-f24 - week05 - steveh

// implementation of student

//C - create
STUDENT CreateStudent(char Name[], int StudentNum) {
	STUDENT newStudent;

	strncpy(newStudent.name, Name, NAME_LENGTH);
	newStudent.studentNum = StudentNum;

	return newStudent;
}

//R - read


//U - update


//D - delete
void DestroyStudent(STUDENT Student) {
	// nothing to do
}


void PrintStudent(STUDENT Student) {
	printf("STUDENT: %s, %d\n", Student.name, Student.studentNum);
}