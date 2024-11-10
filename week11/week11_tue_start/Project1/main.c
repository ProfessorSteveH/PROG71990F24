#include "item.h"
#include "list.h"
#include <stdio.h>

int main(void) {

	PLISTNODE list = NULL;

	Add(&list, CreateItem(1));
	Add(&list, CreateItem(3));
	Add(&list, CreateItem(5));

	Display(list);
	
	Destroy(&list);

	return 0;
}

