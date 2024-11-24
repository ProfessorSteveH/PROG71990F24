#include "item.h"
#include "list.h"
#include <stdio.h>
#include <stdlib.h>

// prog71990-f24 - steveh - week10
// list impl.


void Add(PLISTNODE* list, ITEM i) {
	PLISTNODE newNode = (PLISTNODE)malloc(sizeof(LISTNODE));
	if (!newNode) {
		fprintf(stderr, "error allocating memory\n");
		//exit(EXIT_FAILURE);
		exit(1);
	}
	else {
		newNode->data = CopyItem(i);
		newNode->next = *list;

		*list = newNode;
	}
}

void Display(PLISTNODE list) {
	PLISTNODE current = list;
	while (current != NULL) {
		PrintItem(current->data);
		current = current->next;
	}
}

void Remove(PLISTNODE* list, ITEM i) {
	PLISTNODE current = *list;
	if (current != NULL && CompareItem(current->data, i)) {
		*list = current->next;
		DestroyItem(current->data);
		free(current);
		return;
	}

	PLISTNODE prev = NULL;
	while (current != NULL && !CompareItem(current->data, i)) {
		prev = current;
		current = current->next;
	}

	if (current == NULL)
		return;   // we found the end of the list and no match
	else {
		prev->next = current->next;
		DestroyItem(current->data);
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
		DestroyItem(current->data);
		current = current->next;
		free(tmp);
	}
}
