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
		exit(EXIT_FAILURE);
	}
	else {
		newNode->data = CopyItem(i);
		newNode->next = *list;

		*list = newNode;
	}
}

void Remove(PLISTNODE* list, ITEM i) {
//	PLISTNODE current = *list;
//	if (current != NULL && CompareItem(current->data, i)) {
//		*list = current->next;
//		free(current);
//		return;
//	}
//	PLISTNODE prev = NULL;
//	while(!)
}


void Display(PLISTNODE list) {
	PLISTNODE current = list;
	while (current != NULL) {
		PrintItem(current->data);
		current = current->next;
	}
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
