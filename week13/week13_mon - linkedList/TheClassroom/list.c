#include "participant.h"
#include "list.h"
#include <stdio.h>
#include <stdlib.h>

//prog71990-f24 - steveh - week10
// linkedlist impl

bool Add(PLISTNODE* list, PARTICIPANT p) {
	PLISTNODE newNode = (PLISTNODE)malloc(sizeof(LISTNODE));
	if (!newNode) {
		fprintf(stderr, "error allocating memory\n");
		return false;
	}
	else {
		newNode->data = CopyParticipant(p);
		newNode->next = *list;

		*list = newNode;
		return true;
	}
}

bool Remove(PLISTNODE* list, PARTICIPANT p) {
	PLISTNODE current = *list;
	if (current != NULL && CompareParticipant(current->data, p)) {
		*list = current->next;
		free(current);
		return true;
	}

	PLISTNODE prev = NULL;
	while (current != NULL && !CompareParticipant(current->data, p)) {
		prev = current;
		current = current->next;
	}

	if (current == NULL)
		return false;			// we hit end of list and did not match
	else {	// we found item in list
		prev->next = current->next;
		free(current);
		return true;
	}
}

void Display(PLISTNODE list) {
	PLISTNODE current = list;
	while (current != NULL) {
		PrintParticipant(current->data);
		current = current->next;
	}
}

bool WriteListToStream(PLISTNODE list, FILE* fp) {
	PLISTNODE current = list;
	while (current != NULL) {
		if (!WriteParticipantToStream(current->data, fp))
			return false;
		current = current->next;
	}
	return true;
}

int GetCountOfParticipants(PLISTNODE list) {
	int count = 0;
	PLISTNODE current = list;
	while (current != NULL) {
		count++;
		current = current->next;
	}
	return count;
}


void Empty(PLISTNODE* list) {
	DestroyList(list);
	*list = NULL;
}

void DestroyList(PLISTNODE* list) {
	PLISTNODE current = *list;
	while (current != NULL) {
		PLISTNODE tmp = current;
		DestroyParticipant(current->data);
		current = current->next;
		free(tmp);
	}
	
	//*list = NULL;				// this is the fix, but...
								// would you still add this fix if it were some function like
						// *list = RecreateListFromScratch();  which may take some non-trivial 
								// amount of time??  i might not, choosing instead to add a reminder
								// to the 3-slash header of DestroyList() in list.h
}
