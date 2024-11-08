#pragma once
#include <stdbool.h>

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


#define NAME_MAX_SIZE	60

typedef struct student {			// sizeof(STUDENT=) = 64
	char name[NAME_MAX_SIZE];
	int studentNum;
} STUDENT;

//C - create
STUDENT CreateStudent(char* Name, int StudentNumber);

//R - read
bool WriteStudentToFile(STUDENT s, char* filename);
STUDENT ReadStudentFromFile(char* filename );

//U - update

//D - delete
void DestroyStudent(STUDENT Student);


void PrintStudent(STUDENT Student);

