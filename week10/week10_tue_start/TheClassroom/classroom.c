#include "classroom.h"
#include <string.h>

// prog71990-f24 - steveh- week10
// classroom impl

CLASSROOM CreateClassroom(char* Name) {
	CLASSROOM newClass = { 0 };

	strncpy(newClass.name, Name, MAXNAME);
	
	for (int i = 0; i < CAPACITY; i++)
		newClass.seatStatus[i] = EMPTY;

	return newClass;
}

bool AddParticipantToClassroom(CLASSROOM* class, PARTICIPANT p) {

	for(int i=0; i< CAPACITY; i++)
		if (class->seatStatus[i] == EMPTY) {
			class->seats[i] = p;
			class->seatStatus[i] = FILLED;
			return true;
		}
	return false;
}


bool RemoveParticipantFromClassroom(CLASSROOM* class, PARTICIPANT p) {
	for (int i = 0; i < CAPACITY; i++) {
		if (class->seatStatus[i] == FILLED) {
			if (CompareParticipant(class->seats[i], p)) {
				class->seatStatus[i] = EMPTY;
				return true;
			}		
		}
	}
	return false;
}




bool IsClassroomFull(CLASSROOM class) {
	return (class.currentStudents >= CAPACITY);
}

void PrintClassroom(CLASSROOM class) {
	printf("Classroom: %s\n", class.name);
	for (int i = 0; i < CAPACITY; i++)
		if (class.seatStatus[i] == FILLED)
			PrintParticipant(class.seats[i]);
}

void DestroyClassroom(CLASSROOM* class) {

}