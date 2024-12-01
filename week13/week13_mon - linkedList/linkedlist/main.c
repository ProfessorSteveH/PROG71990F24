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
	Remove(&list, CreateItem(1));
	printf("----\n");
	Display(list);
	//before starting Remove, let's talk about DestroyList a bit more
	// but I would alos like to introduce to your the Principle of least astonishment
	

	DestroyList(&list);
	return 0;
}
//$ make valgrind
//valgrind --tool=memcheck --leak-check=yes --show-reachable=yes --num-callers=20 --track-fds=yes ./main
//==2218582== Memcheck, a memory error detector
//==2218582== Copyright (C) 2002-2022, and GNU GPL'd, by Julian Seward et al.
//==2218582== Using Valgrind-3.22.0 and LibVEX; rerun with -h for copyright info
//==2218582== Command: ./main
//==2218582==
//ITEM: 5
//ITEM: 3
//ITEM: 1
//----
//ITEM: 5
//ITEM: 3
//==2218582==
//==2218582== FILE DESCRIPTORS: 3 open (3 std) at exit.
//==2218582==
//==2218582== HEAP SUMMARY:
//==2218582==     in use at exit: 0 bytes in 0 blocks
//==2218582==   total heap usage: 4 allocs, 4 frees, 1,072 bytes allocated
//==2218582==
//==2218582== All heap blocks were freed -- no leaks are possible
//==2218582==
//==2218582== For lists of detected and suppressed errors, rerun with: -s
//==2218582== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
