#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "student.h"
#include "professor.h"
#include "guest.h"
#include <stdio.h>

// prog71990-f24 - steveh- week10

// interface for the collection that holds all 'allowed participants'

typedef union attendee {			//sizeof(ATTENDEE) == 80
	PROFESSOR professor;
	STUDENT student;
	GUEST guest;
} ATTENDEE;

typedef enum type { STUD, PROF, GST } TYPE;

typedef struct participant {
	TYPE type;		
	ATTENDEE attendee;
} PARTICIPANT;


//C
PARTICIPANT CreateParticipantFromStudent(STUDENT s);
PARTICIPANT CreateParticipantFromProfessor(PROFESSOR p);
PARTICIPANT CreateParticipantFromGuest(GUEST g);

//R
bool WriteParticipantToFile(char* filename, PARTICIPANT p);
PARTICIPANT ReadParticipantFromFile(char* filename);

TYPE GetParticipantType(PARTICIPANT p);

void PrintParticipant(PARTICIPANT p);

//U

//D
void DestroyParticipant(PARTICIPANT p);

