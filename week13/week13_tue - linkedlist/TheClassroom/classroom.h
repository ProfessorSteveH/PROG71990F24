#pragma once
#include "globals.h"
#include "participant.h"
#include "list.h"
#include <stdbool.h>

// prog71990-f24 - steveh- week10

// classroom interface


typedef struct classroom {
	char name[MAX_NAME];
	PLISTNODE participants;
	unsigned int capacity;
} CLASSROOM;

CLASSROOM CreateClassroom(char* Name, unsigned int Capacity);

bool AddParticipantToClassroom(CLASSROOM* class, PARTICIPANT p); 
bool RemoveParticipantFromClassroom(CLASSROOM* class, PARTICIPANT p);

bool IsClassroomFull(CLASSROOM class);
unsigned int GetClassroomCount(CLASSROOM class);

void PrintClassroom(CLASSROOM class);

bool WriteClassroomToFile(CLASSROOM class, char* filename);
bool ReadClassroomFromFile(CLASSROOM* newClass, char* filename);

PLISTNODE SearchForPersonNameInClassroom(CLASSROOM class, char* name);

void DestroyClassroom(CLASSROOM class);
