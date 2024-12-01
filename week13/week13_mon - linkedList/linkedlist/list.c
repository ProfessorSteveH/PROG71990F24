#include "item.h"
#include "list.h"
#include <stdio.h>
#include <stdlib.h>

//prog71990-f24 - steveh - week10
// linkedlist impl

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
	PLISTNODE current = *list;
	if (current != NULL && CompareItem(current->data, i)) {
		*list = current->next;
		free(current);
		return;
	}

	PLISTNODE prev = NULL;
	while (current != NULL && !CompareItem(current->data, i)) {
		prev = current;
		current = current->next;
	}

	if (current == NULL)
		return;			// we hit end of list and did not match
	else {	// we found item in list
		prev->next = current->next;
		free(current);
	}
}

void Display(PLISTNODE list) {
	PLISTNODE current = list;
	while (current != NULL) {
		PrintItem(current->data);
		current = current->next;
	}
}

void Empty(PLISTNODE* list) {
	DestroyList(list);
	*list = NULL;
}

void DestroyList(PLISTNODE* list) {
	PLISTNODE current = *list;
	while (current != NULL) {
		PLISTNODE tmp = current;
		DestroyItem(current->data);
		current = current->next;
		free(tmp);
	}
	
	//*list = NULL;				// this is the fix, but...
								// would you still add this fix if it were some function like
						// *list = RecreateListFromScratch();  which may take some non-trivial 
								// amount of time??  i might not, choosing instead to add a reminder
								// to the 3-slash header of DestroyList() in list.h
}
