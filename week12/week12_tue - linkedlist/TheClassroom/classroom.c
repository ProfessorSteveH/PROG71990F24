#include "globals.h"
#include "classroom.h"
#include "utils.h"
#include <string.h>

// prog71990-f24 - steveh- week10
// classroom impl

CLASSROOM CreateClassroom(char* Name) {
	CLASSROOM newClass = { 0 };

	strncpy(newClass.name, Name, MAX_NAME);
	CleanNewLineFromString(newClass.name);

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
	for (int i = 0; i < CAPACITY; i++)
		if (class.seatStatus[i] == EMPTY)
			return false;

	return true;
}

void PrintClassroom(CLASSROOM class) {
	printf("Classroom: %s\n", class.name);
	for (int i = 0; i < CAPACITY; i++)
		if (class.seatStatus[i] == FILLED)
			PrintParticipant(class.seats[i]);
}

int GetClassroomCount(CLASSROOM class) {
	int count = 0;

	for (int i = 0; i < CAPACITY; i++)
		if (class.seatStatus[i] == FILLED)
			count++;

	return count;
}

bool WriteClassroomToFile(CLASSROOM class, char* filename) {
	FILE* fp = fopen(filename, "w");    // r=> read, w=>write, a=>append
	if (fp == NULL) {  // bad things happened
		fprintf(stderr, "error, not able to open file for writing\n");
		return false;
	}
	fprintf(fp, "%s\n", class.name);
	fprintf(fp, "%d\n", GetClassroomCount(class));
	//iterate over seats
	for (int i = 0; i < CAPACITY; i++)
		if (class.seatStatus[i] == FILLED)
			WriteParticipantToStream(class.seats[i], fp);

	fclose(fp);
	return true;
}

bool ReadClassroomFromFile(CLASSROOM* newClass, char* filename) {
	FILE* fp = fopen(filename, "r");    // r=> read, w=>write, a=>append
	if (fp == NULL) {  // bad things happened
		fprintf(stderr, "error, not able to open file for writing\n");
		return false;
	}

	char buffer[MAX_NAME] = { 0 };
	fgets(buffer, MAX_NAME, fp);

	strncpy(newClass->name, buffer, MAX_NAME);
	CleanNewLineFromString(newClass->name);

	for (int i = 0; i < CAPACITY; i++)
		newClass->seatStatus[i] = EMPTY;

	int count = 0;
	fscanf(fp, "%d\n", &count);

	// populate each seat
	for (int i = 0; i < count; i++) {
		PARTICIPANT p = ReadParticipantFromStream(fp);
		if (!AddParticipantToClassroom(newClass, p))
			fprintf(stderr, "panic!\n");
	}


	fclose(fp);
	return true;
}

void DestroyClassroom(CLASSROOM class) {
	//nothing
}