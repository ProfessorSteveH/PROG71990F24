#include "classroom.h"
#include "participant.h"
#include "utils.h"
#include <string.h>

// prog71900-f24 - steveh - week10

// impl of classroom



CLASSROOM CreateClassroom(char* Name) {
	CLASSROOM c = { 0 };

	strncpy(c.name, Name, MAX_NAME);
	for (int i = 0; i < CAPACITY; i++)
		c.seatStatus[i] = FREE;

	return c;
}

bool IsClassroomFull(CLASSROOM c) {

	for (int i = 0; i < CAPACITY; i++)
		if (c.seatStatus[i] == FREE)
			return false;

	return true;
}

bool AddProfessorToClassroom(CLASSROOM* c, PROFESSOR p) {
	// check that p is valid, if no return false
	if (IsClassroomFull(*c))
		return false;

	int currentSeat = 0;
	while (currentSeat < CAPACITY) {
		if (c->seatStatus[currentSeat] == FREE) {
			c->seats[currentSeat] = CreateParticipantFromProfessor(p);
			c->seatStatus[currentSeat] = FILLED;
			return true;
		}
		currentSeat++;
	}
	
	return false;
}

bool RemoveParticipantFromClassroom(CLASSROOM* c, PARTICIPANT p) {

	for (int i = 0; i < CAPACITY; i++) {
		if (c->seatStatus[i] == FILLED) {
			if (CompareParticipant(c->seats[i], p)) {
				c->seatStatus[i] = FREE;
				return true;
			}
		}
	}
	return false;
}

bool AddStudentToClassroom(CLASSROOM* c, STUDENT s) {
	// check that p is valid, if no return false
	if (IsClassroomFull(*c))
		return false;

	int currentSeat = 0;
	while (currentSeat < CAPACITY) {
		if (c->seatStatus[currentSeat] == FREE) {
			c->seats[currentSeat] = CreateParticipantFromStudent(s);
			c->seatStatus[currentSeat] = FILLED;
			return true;
		}
		currentSeat++;
	}

	return false;
}

bool AddParticipantToClassroom(PARTICIPANT p, CLASSROOM* c) {
	// check that p is valid, if no return false
	if (IsClassroomFull(*c))
		return false;

	int currentSeat = 0;
	while (currentSeat < CAPACITY) {
		if (c->seatStatus[currentSeat] == FREE) {
			c->seats[currentSeat] = p;
			c->seatStatus[currentSeat] = FILLED;
			return true;
		}
		currentSeat++;
	}

	return false;
}

void PrintClassroom(CLASSROOM c) {
	printf("CLASS NAME: %s\n", c.name);
	for (int i = 0; i < CAPACITY; i++)
		if (c.seatStatus[i] == FILLED)
			PrintParticipant(c.seats[i]);
}


bool WriteClassroomToFile(CLASSROOM c, char* filename) {
	FILE* fp = fopen(filename, "w");    // r=> read, w=>write, a=>append
	if (fp == NULL) {  // bad things happened
		fprintf(stderr, "error, not able to open file for writing\n");
		return false;
	}
	fprintf(fp, "%s\n", c.name);
	fprintf(fp, "%d\n", GetCountOfParticipantsInClassroom(c));
	for (int i = 0; i < CAPACITY; i++)
		if (c.seatStatus[i] == FILLED)
			WriteParticipantToStream(c.seats[i], fp);

	fclose(fp);
	return true;
}

int GetCountOfParticipantsInClassroom(CLASSROOM c) {
	int count = 0;
	for (int i = 0; i < CAPACITY; i++)
		if (c.seatStatus[i] == FILLED)
			count++;
	return count;
}

bool ReadClassroomFromFile(CLASSROOM* c, char* filename) {
	FILE* fp = fopen(filename, "r");    // r=> read, w=>write, a=>append
	if (fp == NULL) {  // bad things happened
		fprintf(stderr, "error, not able to open file for writing\n");
		return false;
	}

	char buf[MAX_NAME] = { 0 };
	fgets(buf, MAX_NAME, fp);
	
	CleanNewLineFromString(buf);
	strncpy(c->name, buf, MAX_NAME);		//this duplicates Create
	for (int i = 0; i < CAPACITY; i++)		// introduces D-RY
		c->seatStatus[i] = FREE;

	int count = 0;
	fscanf(fp, "%d\n", &count);

	for (int i = 0; i < count; i++) {
			PARTICIPANT p = ReadParticipantFromStream(fp);
			AddParticipantToClassroom(p, c);
		}
			

	fclose(fp);
	return true;
}

void DestroyClassroom(CLASSROOM c) {
	// nothing
}