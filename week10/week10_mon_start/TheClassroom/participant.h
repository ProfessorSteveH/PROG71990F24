#pragma once
#include "student.h"
#include "professor.h"

// prog71990-f24 - steveh- week10

// interface for the collection that holds all 'allowed participants'

typedef union attendee {			//sizeof(ATTENDEE) == 80
	PROFESSOR professor;
	STUDENT student;
} ATTENDEE;

typedef enum type { STUD, PROF } TYPE;

typedef struct participant {
	TYPE type;		
	ATTENDEE attendee;
} PARTICIPANT;


//C
PARTICIPANT CreateParticipantFromStudent(STUDENT s);
PARTICIPANT CreateParticipantFromProfessor(PROFESSOR p);

//R

//U

//D
void DestroyParticipant(PARTICIPANT p);

