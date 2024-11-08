#include "classroom.h"
#include "participant.h"
#include <string.h>

// prog71900-f24 - steveh - week10

// impl of classroom



CLASSROOM CreateClassroom(char* Name) {
	CLASSROOM c;
	strncpy(c.name, Name, MAX_NAME);
	c.currentSeats = 0;
	for (int i = 0; i < CAPACITY; i++)
		c.seatStatus[i] = FREE;
	return c;
}

bool IsClassroomFull(CLASSROOM c) {
	return (c.currentSeats > CAPACITY-1);
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

bool RemoveProfessorFromClassroom(CLASSROOM* c, PROFESSOR p) {

	for (int i = 0; i < CAPACITY; i++) {
		if(c->seatStatus[i] == FILLED)
			if (GetParticipantType(c->seats[i]) == PROF) {
				if (CompareProfessors(GetProfessorFromParticipant(c->seats[i]), p)) {
					c->seatStatus[i] = FREE;
					return true;
				}
			}
	}

	return false;
}

bool AddStudentToClassroom(CLASSROOM* c, STUDENT s) {

}

void PrintClassroom(CLASSROOM c) {

}

void DestroyClassroom(CLASSROOM c) {
	// nothing
}