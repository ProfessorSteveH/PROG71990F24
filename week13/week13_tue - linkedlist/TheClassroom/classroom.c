#include "globals.h"
#include "classroom.h"
#include "utils.h"
#include "list.h"
#include <string.h>

// prog71990-f24 - steveh- week10
// classroom impl

CLASSROOM CreateClassroom(char* Name, unsigned int Capacity) {
	CLASSROOM newClass = { 0 };

	strncpy(newClass.name, Name, MAX_NAME);
	CleanNewLineFromString(newClass.name);

	newClass.participants = NULL;

	newClass.capacity = Capacity;

	return newClass;
}

bool AddParticipantToClassroom(CLASSROOM* class, PARTICIPANT p) {
	return Add(&(class->participants), p);
}



bool RemoveParticipantFromClassroom(CLASSROOM* class, PARTICIPANT p) {
	return Remove(&(class->participants), p);
}


bool IsClassroomFull(CLASSROOM class) {
	return (GetClassroomCount(class) >= class.capacity);
}

void PrintClassroom(CLASSROOM class) {
	printf("Classroom: %s\n", class.name);
	Display(class.participants);
}

unsigned int GetClassroomCount(CLASSROOM class) {
	return GetListCount(class.participants);
}

bool WriteClassroomToFile(CLASSROOM class, char* filename) {
	FILE* fp = fopen(filename, "w");    // r=> read, w=>write, a=>append
	if (fp == NULL) {  // bad things happened
		fprintf(stderr, "error, not able to open file for writing\n");
		return false;
	}

	fprintf(fp, "%s\n", class.name);

	fprintf(fp, "%d\n", class.capacity);
	fprintf(fp, "%d\n", GetClassroomCount(class));
	WriteListToStream(class.participants, fp);

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

	int capacity = 0;
	fscanf(fp, "%d\n", &capacity);
	newClass->capacity = capacity;

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
	Destroy(&(class.participants));
}