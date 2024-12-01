#define _CRT_SECURE_NO_WARNINGS

#include "globals.h"
#include "student.h"
#include "utils.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// prog71990-f24 - week10 - steveh

// implementation of student


//C - create
STUDENT CreateStudent(char* Name, int StudentNum) {
	STUDENT newStudent;

	strncpy(newStudent.name, Name, MAX_NAME);
	CleanNewLineFromString(newStudent.name);					// here is a validation to keep name proper

	newStudent.studentNum = StudentNum;

	return newStudent;
}

//R - read
bool WriteStudentToStream(FILE* fp, STUDENT s) {

	fprintf(fp, "%s\n", s.name);
	fprintf(fp, "%d\n", s.studentNum);

	return true;
}

// we don't deal well with errors.  we will fix this in coming weeks!
// also - this breaks our design goal of encapsulation/data hiding...  
//			if we have 'hidden' state that is initialized in Create, we will
//			fail to do the right thing in our code.
// the fix will be applied below.  The original code will be commented and
// left for illustration.
STUDENT ReadStudentFromStream(FILE* fp) {

	char tempBuffer[MAX_NAME] = { 0 };
	char* result = fgets(tempBuffer, MAX_NAME, fp);
	if (result == NULL) {  // bad things happened
		fprintf(stderr, "error, not able to read name from file\n");
		exit(EXIT_FAILURE);
	}
	int tmpStudentNum;
	int numResult = fscanf(fp, "%d\n", &tmpStudentNum);
	if (numResult != 1) {
		fprintf(stderr, "error, not able to read studentnum from file\n");
		exit(EXIT_FAILURE);
	}

	return CreateStudent(tempBuffer, tmpStudentNum);
}

//U - update


//D - delete
void DestroyStudent(STUDENT Student) {
	// nothing to do
}

bool CompareStudent(STUDENT lhs, STUDENT rhs) {
	return (lhs.studentNum == rhs.studentNum);
}

STUDENT CopyStudent(STUDENT src) {
	return CreateStudent(src.name, src.studentNum);
}

void PrintStudent(STUDENT Student) {
	printf("STUDENT: %s, %d\n", Student.name, Student.studentNum);
}