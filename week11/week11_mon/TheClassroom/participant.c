#include "globals.h"
#include "participant.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// prog71990-f24 - steveh - week10

// participant implementation


//C
PARTICIPANT CreateParticipantFromStudent(STUDENT s) {
	PARTICIPANT newParticipant = { 0 };
	newParticipant.type = STUD;
	newParticipant.attendee.student = s;
	return newParticipant;
}

PARTICIPANT CreateParticipantFromProfessor(PROFESSOR p) {
	PARTICIPANT newParticipant = { 0 };
	newParticipant.type = PROF;
	newParticipant.attendee.professor = p;
	return newParticipant;
}

PARTICIPANT CreateParticipantFromGuest(GUEST g) {
	PARTICIPANT newParticipant = { 0 };
	newParticipant.type = GST;
	newParticipant.attendee.guest = g;
	return newParticipant;
}

//R
bool WriteParticipantToFile(char* filename, PARTICIPANT p) {
	FILE* fp = fopen(filename, "w");    // r=> read, w=>write, a=>append
	if (fp == NULL) {  // bad things happened
		fprintf(stderr, "error, not able to open file for writing\n");
		return false;
	}

	switch (p.type) {
	case PROF:	fprintf(fp, "PROFESSOR");
				WriteProfessorToStream(fp, p.attendee.professor);
				break;
	case STUD:  fprintf(fp, "STUDENT"); 
				WriteStudentToStream(fp, p.attendee.student);
				break;
	case GST:	fprintf(fp, "GUEST"); 
				WriteGuestToStream(fp, p.attendee.guest);
				break;
	default:	fprintf(stderr, "unkown attendee type\n");
				break;
	}

	fclose(fp);
	return true;
}

PARTICIPANT ReadParticipantFromFile(char* filename) {
	FILE* fp = fopen(filename, "r");    // r=> read, w=>write, a=>append
	if (fp == NULL) {  // bad things happened
		fprintf(stderr, "error, not able to open file for reading\n");
		exit(EXIT_FAILURE);
	}

	char type[MAX_NAME] = { 0 };
	char* result = fgets(type, MAX_NAME, fp);
	if (result == NULL) {  // bad things happened
		fprintf(stderr, "error, not able to read type from file\n");
		exit(EXIT_FAILURE);
	}

	if (strncmp(type, "STUDENT", strlen("STUDENT")) == 0) {
		STUDENT newStudent = ReadStudentFromStream(fp);
		return CreateParticipantFromStudent(newStudent);
	}
	else if (strncmp(type, "PROFESSOR", strlen("PROFESSOR")) == 0) {
		PROFESSOR newProfessor = ReadProfessorFromStream(fp);
		return CreateParticipantFromProfessor(newProfessor);
	}
	else if (strncmp(type, "GUEST", strlen("GUEST")) == 0) {
		GUEST newGuest = ReadGuestFromStream(fp);
		return CreateParticipantFromGuest(newGuest);
	}
	else {
		fprintf(stderr, "disaster!  exiting...\n");
		exit(EXIT_FAILURE);
	}
}


bool CompareParticipant(PARTICIPANT lhs, PARTICIPANT rhs) {

	if (lhs.type != rhs.type)
		return false;
	else {
		switch (lhs.type) {
		case(STUD):	return CompareStudent(lhs.attendee.student, rhs.attendee.student);
					break;
		case(PROF): return CompareProfessors(lhs.attendee.professor, rhs.attendee.professor);
					break;
		case(GST):	return CompareGuest(lhs.attendee.guest, rhs.attendee.guest);
					break;
		default:	fprintf(stderr, "error comparing participant\n");
					return false;
		}
	}

}

TYPE GetParticipantType(PARTICIPANT p) {
	return p.type;
}

void PrintParticipant(PARTICIPANT p) {
	switch(p.type) {
		case PROF:	PrintProfessor(p.attendee.professor);
					break;
		case STUD:  PrintStudent(p.attendee.student);
					break;
		case GST:	PrintGuest(p.attendee.guest);
					break;
		default:	fprintf(stderr, "unkown attendee type\n");
					break;
	}
}


//U

//D
void DestroyParticipant(PARTICIPANT p) {
	//nothing
}
