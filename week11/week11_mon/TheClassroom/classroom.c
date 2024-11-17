#include "classroom.h"
#include "participant.h"
#include <string.h>

// prog71900-f24 - steveh - week10

// impl of classroom



CLASSROOM CreateClassroom(char* Name) {
	CLASSROOM c;
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

void PrintClassroom(CLASSROOM c) {
	printf("CLASS NAME: %s\n", c.name);
	for (int i = 0; i < CAPACITY; i++)
		if (c.seatStatus[i] == FILLED)
			PrintParticipant(c.seats[i]);
}


bool WriteClassroomToFile(CLASSROOM c, char* filename) {

}

void DestroyClassroom(CLASSROOM c) {
	// nothing
}