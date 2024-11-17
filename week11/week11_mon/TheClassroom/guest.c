#include "guest.h"
#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// interface for our guest ADT  (abstract data type)

// steveh - prog71990 - week11

//C - create
GUEST CreateGuest(char* Name) {
	GUEST newGuest = {0};
	strncpy(newGuest.name, Name, MAX_NAME);
	CleanNewLineFromString(newGuest.name);
	return newGuest;
}

//R - read
bool WriteGuestToStream(FILE* fp, GUEST g) {

	fprintf(fp, "%s\n", g.name);

	return true;
}

GUEST ReadGuestFromStream(FILE* fp) {

	char tempBuffer[MAX_NAME] = { 0 };
	char* result = fgets(tempBuffer, MAX_NAME, fp);
	if (result == NULL) {  // bad things happened
		fprintf(stderr, "error, not able to read name from file\n");
		exit(EXIT_FAILURE);
	}

	return CreateGuest(tempBuffer);
}

bool CompareGuest(GUEST lhs, GUEST rhs) {
	if (lhs.name == NULL || rhs.name == NULL)
		return false;

	return (strncmp(lhs.name, rhs.name, strlen(lhs.name)) == 0);
}

GUEST CopyGuest(GUEST src) {
	return CreateGuest(src.name);
}


//U - update

//D - delete
void DestroyGuest(GUEST Guest) {
	//nothing
}

void PrintGuest(GUEST Guest) {
	printf("GUEST: %s\n", Guest.name);
}