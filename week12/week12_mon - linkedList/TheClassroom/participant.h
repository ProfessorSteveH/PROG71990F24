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

typedef enum type { NONE, STUD, PROF, GST } TYPE;

typedef struct participant {
	TYPE type;		
	ATTENDEE attendee;
} PARTICIPANT;


//C
PARTICIPANT CreateParticipantFromStudent(STUDENT s);
PARTICIPANT CreateParticipantFromProfessor(PROFESSOR p);
PARTICIPANT CreateParticipantFromGuest(GUEST g);



//R
bool WriteParticipantToStream(PARTICIPANT p, FILE* fp);

PARTICIPANT ReadParticipantFromStream(FILE* fp);


PARTICIPANT CopyParticipant(PARTICIPANT src);

bool CompareParticipant(PARTICIPANT lhs, PARTICIPANT rhs);

void PrintParticipant(PARTICIPANT p);

//U

//D
void DestroyParticipant(PARTICIPANT p);

