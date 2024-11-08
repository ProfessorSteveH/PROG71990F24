#include "item.h"
#include "list.h"
#include <stdio.h>

// prog71990-f24 - steveh -week10
// exercise linked list

int main(void) {

	PLISTNODE list = NULL;

	Add(&list, CreateItem(1));
	Add(&list, CreateItem(3));
	Add(&list, CreateItem(5));

	Display(list);


	DestroyList(&list);
	return 0;
}