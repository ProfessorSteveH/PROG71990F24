#pragma once

// interface for our student ADT  (abstract data type)

// steveh - prog71990 - week05

#define NAME_LENGTH		40

typedef struct student {
	char name[NAME_LENGTH];
	int studentNum;
} STUDENT;

//C - create
STUDENT CreateStudent(char Name[], int StudentNum);

//R - read


//U - update


//D - delete
void DestroyStudent(STUDENT Student);

void PrintStudent(STUDENT Student);