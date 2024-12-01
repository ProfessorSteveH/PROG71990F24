#include "participant.h"
#include "list.h"
#include <stdio.h>
#include <stdlib.h>

// prog71990-f24 - steveh - week10
// list impl.


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

int GetListCount(PLISTNODE list) {
	int count = 0;
	PLISTNODE current = list;
	while (current != NULL) {
		count++;
		current = current->next;
	}
	return count;
}

bool Remove(PLISTNODE* list, PARTICIPANT p) {
	PLISTNODE current = *list;
	if (current != NULL && CompareParticipant(current->data, p)) {
		*list = current->next;
		DestroyParticipant(current->data);
		free(current);
		return true;
	}

	PLISTNODE prev = NULL;
	while (current != NULL && !CompareParticipant(current->data, p)) {
		prev = current;
		current = current->next;
	}

	if (current == NULL)
		return false;   // we found the end of the list and no match
	else {
		prev->next = current->next;
		DestroyParticipant(current->data);
		free(current);
		return true;
	}
}

void Clear(PLISTNODE* list) {
	Destroy(list);
	*list = NULL;
}

void Destroy(PLISTNODE* list) {
	PLISTNODE current = *list;
	while (current != NULL) {
		PLISTNODE tmp = current;
		DestroyParticipant(current->data);
		current = current->next;
		free(tmp);
	}
}
