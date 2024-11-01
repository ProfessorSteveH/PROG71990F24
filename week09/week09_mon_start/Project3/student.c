#define _CRT_SECURE_NO_WARNINGS

#include "student.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// prog71990-f24 - week05 - steveh

// implementation of student

// we can add a small utility function here (and mark it static to keep it private)
// to remove the trailing \n from any submitted name 
// and any other validations we need
static void nameValidate(char* Name) {
	for (int i = 0; i < strlen(Name); i++)
		if (Name[i] == '\n')
			Name[i] = '\0';
}


//C - create
STUDENT CreateStudent(char Name[], int StudentNum) {
	STUDENT newStudent;

	strncpy(newStudent.name, Name, NAME_LENGTH);
	nameValidate(newStudent.name);					// here is a validation to keep name proper

	newStudent.studentNum = StudentNum;

	return newStudent;
}

//R - read
bool WriteStudentToFile(STUDENT s, char filename[]) {
	FILE* fp = fopen(filename, "w");    // r=> read, w=>write, a=>append
	if (fp == NULL) {  // bad things happened
		fprintf(stderr, "error, not able to open file for writing\n");
		return false;
	}
	fprintf(fp, "%s\n", s.name);
	fprintf(fp, "%d\n", s.studentNum);

	fclose(fp);
	return true;
}

// we don't deal well with errors.  we will fix this in coming weeks!
// also - this breaks our design goal of encapsulation/data hiding...  
//			if we have 'hidden' state that is initialized in Create, we will
//			fail to do the right thing in our code.
// the fix will be applied below.  The original code will be commented and
// left for illustration.
STUDENT ReadStudentFromFile(char* filename) {
	FILE* fp = fopen(filename, "r");
	if (fp == NULL) {  // bad things happened
		fprintf(stderr, "error, not able to open file for writing\n");
		exit(EXIT_FAILURE);
	}
//start of original
	//STUDENT newStudent;
	//char* result = fgets(newStudent.name, NAME_LENGTH, fp);
	//if (result == NULL) {  // bad things happened
	//	fprintf(stderr, "error, not able to read name from file\n");
	//	exit(EXIT_FAILURE);
	//}
	//int numResult = fscanf(fp, "%d", &newStudent.studentNum);

	//fclose(fp);
	//return newStudent;
//end of original
	char tempBuffer[NAME_LENGTH] = { 0 };
	char* result = fgets(tempBuffer, NAME_LENGTH, fp);
	if (result == NULL) {  // bad things happened
		fprintf(stderr, "error, not able to read name from file\n");
		exit(EXIT_FAILURE);
	}
	int tmpStudentNum;
	int numResult = fscanf(fp, "%d", &tmpStudentNum);
	if (numResult != 1) {
		fprintf(stderr, "error, not able to read studentnum from file\n");
		exit(EXIT_FAILURE);
	}
	fclose(fp);
	return CreateStudent(tempBuffer, tmpStudentNum);
}

//U - update


//D - delete
void DestroyStudent(STUDENT Student) {
	// nothing to do
}


void PrintStudent(STUDENT Student) {
	printf("STUDENT: %s, %d\n", Student.name, Student.studentNum);
}