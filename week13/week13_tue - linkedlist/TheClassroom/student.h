#pragma once
#include "globals.h"
#include <stdbool.h>
#include <stdio.h>

// interface for our new student ADT (abstract data type)

// steveh - prog71990-f24 - week10

// let's introduce streams -> a line of things in a row in motion
//		stdin => keyboard, mouse, output from another process, touchscreen, network
//		stdout => screen, network, speakers, files, devices
//		stderr => where errors go, by default directed to stdout

//printf("%d\n", age);
//fprintf(stdout, "%d\n", age);
//scanf("%d", &age);
//fscanf(stdin, "%d", &age);
//FILE* fp = fopen("filename.txt", "w")
//fprintf(fp, "%d\n", age);


typedef struct student {			// sizeof(STUDENT=) = 64
	char name[MAX_NAME];
	int studentNum;
} STUDENT;

//C - create
STUDENT CreateStudent(char* Name, int StudentNumber);

//R - read
bool WriteStudentToStream(FILE* fp, STUDENT s);
STUDENT ReadStudentFromStream(FILE* fp);


bool CompareStudent(STUDENT lhs, STUDENT rhs);
STUDENT CopyStudent(STUDENT src);

//U - update

//D - delete
void DestroyStudent(STUDENT Student);


void PrintStudent(STUDENT Student);

