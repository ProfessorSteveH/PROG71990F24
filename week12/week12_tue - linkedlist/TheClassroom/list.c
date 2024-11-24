#include "participant.h"
#include "list.h"
#include <stdio.h>
#include <stdlib.h>

// prog71990-f24 - steveh - week10
// list impl.


void Add(PLISTNODE* list, PARTICIPANT p) {
	PLISTNODE newNode = (PLISTNODE)malloc(sizeof(LISTNODE));
	if (!newNode) {
		fprintf(stderr, "error allocating memory\n");
		//exit(EXIT_FAILURE);
		exit(1);
	}
	else {
		newNode->data = CopyParticipant(p);
		newNode->next = *list;

		*list = newNode;
	}
}

void Display(PLISTNODE list) {
	PLISTNODE current = list;
	while (current != NULL) {
		PrintParticipant(current->data);
		current = current->next;
	}
}

void Remove(PLISTNODE* list, PARTICIPANT p) {
	PLISTNODE current = *list;
	if (current != NULL && CompareParticipant(current->data, p)) {
		*list = current->next;
		DestroyItem(current->data);
		free(current);
		return;
	}

	PLISTNODE prev = NULL;
	while (current != NULL && !CompareParticipant(current->data, p)) {
		prev = current;
		current = current->next;
	}

	if (current == NULL)
		return;   // we found the end of the list and no match
	else {
		prev->next = current->next;
		DestroyParticipant(current->data);
		free(current);
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
