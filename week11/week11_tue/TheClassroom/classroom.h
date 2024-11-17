#pragma once
#include "globals.h"
#include "participant.h"
#include <stdbool.h>

// prog71990-f24 - steveh- week10

// classroom interface

typedef enum status { EMPTY, FILLED } STATUS;

typedef struct classroom {
	char name[MAX_NAME];
	PARTICIPANT seats[CAPACITY];
	STATUS seatStatus[CAPACITY];
} CLASSROOM;

CLASSROOM CreateClassroom(char* Name);

bool AddParticipantToClassroom(CLASSROOM* class, PARTICIPANT p); 
bool RemoveParticipantFromClassroom(CLASSROOM* class, PARTICIPANT p);

bool IsClassroomFull(CLASSROOM class);

void PrintClassroom(CLASSROOM class);

bool WriteClassroomToFile(CLASSROOM class, char* filename);
bool ReadClassroomFromFile(CLASSROOM* newClass, char* filename);

void DestroyClassroom(CLASSROOM class);
