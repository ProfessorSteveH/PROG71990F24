#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "globals.h"
#include <stdbool.h>
#include <stdio.h>

// interface for our student ADT  (abstract data type)

// steveh - prog71990 - week10

// streams:
//		a stream is just a collection of bytes in sequential order in motion
//   stdin -> keyboard (also could be network, touch screen, sensor)
//   stdout -> screen (also same as above)
//   stderr -> generally the same as stdout, unless specified
//     FILE *  (an opened file, often called fp (variable name))

//printf("%s\n", name);
//fprintf(stdout, "%s\n", name);
//fprintf(fp, "%s\n", name);
//
//scanf("%d", &a);
//fscanf(stdin, "%d", &a);
//fscanf(fp, "%d", &a);


typedef struct student {	//sizeof(STUDENT) == 
	char name[MAX_NAME];  
	int studentNum;          //  4
} STUDENT;

//C - create
STUDENT CreateStudent(char* Name, int StudentNum);

//R - read
bool WriteStudentToStream(FILE* fp, STUDENT s);
STUDENT ReadStudentFromStream(FILE* fp);		// we have some technical debt here... we will return to fix!

//U - update
bool CompareStudents(STUDENT lhs, STUDENT rhs);


//D - delete
void DestroyStudent(STUDENT Student);

void PrintStudent(STUDENT Student);