#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "globals.h"
#include "participant.h"
#include <stdbool.h>

// prog71900f24 - steveh - week10

// our classroom interface


typedef enum status { FREE, FILLED } STATUS;

typedef struct classroom {
	char name[MAX_NAME];
	PARTICIPANT seats[CAPACITY];
	STATUS seatStatus[CAPACITY];
} CLASSROOM;

bool IsClassroomFull(CLASSROOM c);

CLASSROOM CreateClassroom(char* Name);
bool AddProfessorToClassroom(CLASSROOM* c, PROFESSOR p);
bool AddStudentToClassroom(CLASSROOM* c, STUDENT s);
bool AddParticipantToClassroom(PARTICIPANT p, CLASSROOM* c);

bool RemoveParticipantFromClassroom(CLASSROOM* class, PARTICIPANT p);
bool RemovePersonFromClassroom(CLASSROOM* class, char* name);

void PrintClassroom(CLASSROOM c);
bool WriteClassroomToFile(CLASSROOM c, char* filename);

bool ReadClassroomFromFile(CLASSROOM* c, char* filename);

int GetCountOfParticipantsInClassroom(CLASSROOM c);

void DestroyClassroom(CLASSROOM c);
