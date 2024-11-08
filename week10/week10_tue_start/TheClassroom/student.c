#define _CRT_SECURE_NO_WARNINGS
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
STUDENT CreateStudent(char Name[], int StudentNumber) {
	STUDENT newStudent;

	validate_name(Name);

	strncpy(newStudent.name, Name, NAME_MAX_SIZE);
	newStudent.studentNum = StudentNumber;

	return newStudent;
}

//R - read
bool WriteStudentToFile(STUDENT s, char filename[]) {
	FILE* fp = fopen(filename, "w");
	if (fp == NULL) {
		fprintf(stderr, "failed to open file\n");
		return false;
	}

	fprintf(fp, "%s\n", s.name);
	fprintf(fp, "%d\n", s.studentNum);

	fclose(fp);

	return true;
}

STUDENT ReadStudentFromFile(char* filename) {
	FILE* fpRead = fopen(filename, "r");
	if (fpRead == NULL) {
		fprintf(stderr, "failed to open file for read\n");
		exit(1);
	}

	char buffer[NAME_MAX_SIZE] = { 0 };
	fgets(buffer, NAME_MAX_SIZE, fpRead);

	int tmpStudentNum;
	fscanf(fpRead, "%d", &tmpStudentNum);
	fclose(fpRead);

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