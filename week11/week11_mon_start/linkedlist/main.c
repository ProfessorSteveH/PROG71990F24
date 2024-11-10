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

	//before starting Remove, let's talk about DestroyList a bit more
	// but I would alos like to introduce to your the Principle of least astonishment
	

	DestroyList(&list);
	Add(&list, CreateItem(1));		//a bad thing hapens here...
	Display(list);					// but only shows up here!
	return 0;
}

//$ make valgrind
//valgrind --tool=memcheck --leak-check=yes --show-reachable=yes --num-callers=20 --track-fds=yes ./main
//==1345268== Memcheck, a memory error detector
//==1345268== Copyright (C) 2002-2022, and GNU GPL'd, by Julian Seward et al.
//==1345268== Using Valgrind-3.22.0 and LibVEX; rerun with -h for copyright info
//==1345268== Command: ./main
//==1345268==
//ITEM: 5
//ITEM: 3
//ITEM: 1
//==1345268==
//==1345268== FILE DESCRIPTORS: 3 open (3 std) at exit.
//==1345268==
//==1345268== HEAP SUMMARY:
//==1345268==     in use at exit: 0 bytes in 0 blocks
//==1345268==   total heap usage: 4 allocs, 4 frees, 1,072 bytes allocated
//==1345268==
//==1345268== All heap blocks were freed -- no leaks are possible
//==1345268==
//==1345268== For lists of detected and suppressed errors, rerun with: -s
//==1345268== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
