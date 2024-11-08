#pragma once
#include "participant.h"
#include <stdbool.h>

// prog71900f24 - steveh - week10

// our classroom interface

#define MAX_NAME	 60
#define CAPACITY	 40

typedef enum status { FREE, FILLED } STATUS;

typedef struct classroom {
	char name[MAX_NAME];
	PARTICIPANT seats[CAPACITY];
	int currentSeats;
	STATUS seatStatus[CAPACITY];
} CLASSROOM;

bool IsClassroomFull(CLASSROOM c);

CLASSROOM CreateClassroom(char* Name);
bool AddProfessorToClassroom(CLASSROOM* c, PROFESSOR p);
bool AddStudentToClassroom(CLASSROOM* c, STUDENT s);

bool RemoveProfessorFromClassroom(CLASSROOM* c, PROFESSOR p);

void PrintClassroom(CLASSROOM c);

void DestroyClassroom(CLASSROOM c);
