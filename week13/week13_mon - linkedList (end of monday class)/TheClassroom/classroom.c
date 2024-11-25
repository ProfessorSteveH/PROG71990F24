#include "classroom.h"
#include "participant.h"
#include "utils.h"
#include <string.h>

// prog71900-f24 - steveh - week10

// impl of classroom



CLASSROOM CreateClassroom(char* Name, int Capacity) {
	CLASSROOM c = { 0 };

	strncpy(c.name, Name, MAX_NAME);
	c.capacity = Capacity;
	c.seats = NULL;

	return c;
}

bool IsClassroomFull(CLASSROOM c) {

	if (GetCountOfParticipantsInClassroom(c) >= c.capacity)
		return true;

	return false;
}

bool AddProfessorToClassroom(CLASSROOM* c, PROFESSOR p) {
	// check that p is valid, if no return false
	if (IsClassroomFull(*c))
		return false;

	return Add(&(c->seats), CreateParticipantFromProfessor(p));
}

bool RemoveParticipantFromClassroom(CLASSROOM* c, PARTICIPANT p) {
	return Remove(&(c->seats), p);
}

bool AddStudentToClassroom(CLASSROOM* c, STUDENT s) {
	// check that p is valid, if no return false
	if (IsClassroomFull(*c))
		return false;

	return Add(&(c->seats), CreateParticipantFromStudent(s));
}

bool AddParticipantToClassroom(PARTICIPANT p, CLASSROOM* c) {
	// check that p is valid, if no return false
	if (IsClassroomFull(*c))
		return false;

	return Add(&(c->seats), p);
}

void PrintClassroom(CLASSROOM c) {
	printf("CLASS NAME: %s\n", c.name);
	Display(c.seats);
}


bool WriteClassroomToFile(CLASSROOM c, char* filename) {
	FILE* fp = fopen(filename, "w");    // r=> read, w=>write, a=>append
	if (fp == NULL) {  // bad things happened
		fprintf(stderr, "error, not able to open file for writing\n");
		return false;
	}
	fprintf(fp, "%s\n", c.name);
	fprintf(fp, "%d\n", c.capacity);
	fprintf(fp, "%d\n", GetCountOfParticipantsInClassroom(c));
	bool writeResult = WriteListToStream(c.seats, fp);

	fclose(fp);
	return writeResult;
}

int GetCountOfParticipantsInClassroom(CLASSROOM c) {
	return GetCountOfParticipants(c.seats);
}

bool ReadClassroomFromFile(CLASSROOM* c, char* filename) {
	FILE* fp = fopen(filename, "r");    // r=> read, w=>write, a=>append
	if (fp == NULL) {  // bad things happened
		fprintf(stderr, "error, not able to open file for writing\n");
		return false;
	}

	char buf[MAX_NAME] = { 0 };
	fgets(buf, MAX_NAME, fp);
	
	int capacity = 0;
	fscanf("%d\n", &capacity);

	*c = CreateClassroom(buf, capacity);
	//CleanNewLineFromString(buf);
	//strncpy(c->name, buf, MAX_NAME);		//this duplicates Create

	int count = 0;
	fscanf(fp, "%d\n", &count);

	for (int i = 0; i < count; i++) {
			PARTICIPANT p = ReadParticipantFromStream(fp);
			//TODO deal with fail (likely a fail on malloc)
			AddParticipantToClassroom(p, c);
		}
			

	fclose(fp);
	return true;
}

void DestroyClassroom(CLASSROOM c) {
	// nothing
}