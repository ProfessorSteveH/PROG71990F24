#define _CRT_SECURE_NO_WARNINGS
#include "globals.h"
#include "student.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

//prog71900-f24 - steveh - week10

// student implementation

// static = visible only to this TU (translation unit) (a .c file)
static void validate_name(char* Name) {
	// removes any newline chars from name string
	for (int i = 0; i < strlen(Name); i++)
		if (Name[i] == '\n')
			Name[i] = '\0';

	// remove ' char

}

//C - create
STUDENT CreateStudent(char* Name, int StudentNumber) {
	STUDENT newStudent;

	validate_name(Name);

	strncpy(newStudent.name, Name, MAX_NAME);
	newStudent.studentNum = StudentNumber;

	return newStudent;
}

bool CompareStudent(STUDENT lhs, STUDENT rhs) {
	return (lhs.studentNum == rhs.studentNum);
}

//R - read
bool WriteStudentToStream(FILE* fp, STUDENT s) {

	fprintf(fp, "%s\n", s.name);
	fprintf(fp, "%d\n", s.studentNum);

	return true;
}

STUDENT ReadStudentFromStream(FILE* fp) {

	char buffer[MAX_NAME] = { 0 };
	fgets(buffer, MAX_NAME, fp);

	int tmpStudentNum;
	fscanf(fp, "%d\n", &tmpStudentNum);

	return CreateStudent(buffer, tmpStudentNum);
}

//U - update

//D - delete
void DestroyStudent(STUDENT Student) {
	// either set attributes to null or
	// do nothing.
}

void PrintStudent(STUDENT Student) {
	printf("STUDENT: %s, %d\n", Student.name, Student.studentNum);
}