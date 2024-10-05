#pragma once

// interface for our new student ADT (abstract data type)

// steveh - prog71990-f24 - week05

#define NAME_MAX_SIZE	60

typedef struct student {
	char name[NAME_MAX_SIZE];
	int studentNum;
} STUDENT;

//C - create
STUDENT CreateStudent(char[], int);

//R - read

//U - update

//D - delete

