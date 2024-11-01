#pragma once
#include <stdbool.h>

// interface for our student ADT  (abstract data type)

// steveh - prog71990 - week05

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

#define NAME_LENGTH		40

typedef struct student {	
	char name[NAME_LENGTH];  
	int studentNum;          //  4
} STUDENT, *PSTUDENT;

//C - create
PSTUDENT CreateStudent(char* Name, int StudentNum);

//R - read
bool WriteStudentToFile(PSTUDENT s, char* filename);
PSTUDENT ReadStudentFromFile(char* filename);		// we have some technical debt here... we will return to fix!

//U - update


//D - delete
void DestroyStudent(PSTUDENT Student);

void PrintStudent(PSTUDENT Student);