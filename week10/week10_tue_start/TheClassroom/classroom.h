#pragma once
#include "participant.h"
#include <stdbool.h>

// prog71990-f24 - steveh- week10

// classroom interface

#define MAXNAME		60
#define CAPACITY	40

typedef enum status { EMPTY, FILLED } STATUS;

typedef struct classroom {
	char name[MAXNAME];
	PARTICIPANT seats[CAPACITY];
	STATUS seatStatus[CAPACITY];
} CLASSROOM;

CLASSROOM CreateClassroom(char* Name);

bool AddParticipantToClassroom(CLASSROOM* class, PARTICIPANT p); 
bool RemoveParticipantFromClassroom(CLASSROOM* class, PARTICIPANT p);

bool IsClassroomFull(CLASSROOM class);

void PrintClassroom(CLASSROOM class);

void DestroyClassroom(CLASSROOM* class);
