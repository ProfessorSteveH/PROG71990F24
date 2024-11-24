#include "item.h"
#include "list.h"
#include <stdio.h>

int counter;

int main(void) {

	PLISTNODE list = NULL;

	Add(&list, CreateItem(1));
	Add(&list, CreateItem(3));
	Add(&list, CreateItem(5));

	Display(list);
	Remove(&list, CreateItem(3));
	printf("-----\n");
	Display(list);
	
	Destroy(&list);
	return 0;
}
//$ make valgrind
//valgrind --tool=memcheck --leak-check=yes --show-reachable=yes --num-callers=20 --track-fds=yes ./main
//==2218951== Memcheck, a memory error detector
//==2218951== Copyright (C) 2002-2022, and GNU GPL'd, by Julian Seward et al.
//==2218951== Using Valgrind-3.22.0 and LibVEX; rerun with -h for copyright info
//==2218951== Command: ./main
//==2218951==
//ITEM: 5
//ITEM: 3
//ITEM: 1
//-----
//ITEM: 5
//ITEM: 1
//==2218951==
//==2218951== FILE DESCRIPTORS: 3 open (3 std) at exit.
//==2218951==
//==2218951== HEAP SUMMARY:
//==2218951==     in use at exit: 0 bytes in 0 blocks
//==2218951==   total heap usage: 4 allocs, 4 frees, 1,072 bytes allocated
//==2218951==
//==2218951== All heap blocks were freed -- no leaks are possible
//==2218951==
//==2218951== For lists of detected and suppressed errors, rerun with: -s
//==2218951== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

