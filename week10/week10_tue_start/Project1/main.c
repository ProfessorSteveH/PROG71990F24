#include "item.h"
#include "list.h"
#include <stdio.h>

int main(void) {

	PLISTNODE list = NULL;

	Add(&list, CreateItem(1));
	Add(&list, CreateItem(3));
	Add(&list, CreateItem(5));

	Display(list);
	
	Remove(&list, CreateItem(3));

	Destroy(&list);

	return 0;
}

//$ make valgrind
//valgrind --tool=memcheck --leak-check=yes --show-reachable=yes --num-callers=20 --track-fds=yes ./main
//==1344841== Memcheck, a memory error detector
//==1344841== Copyright (C) 2002-2022, and GNU GPL'd, by Julian Seward et al.
//==1344841== Using Valgrind-3.22.0 and LibVEX; rerun with -h for copyright info
//==1344841== Command: ./main
//==1344841==
//ITEM: 5
//ITEM: 3
//ITEM: 1
//==1344841==
//==1344841== FILE DESCRIPTORS: 3 open (3 std) at exit.
//==1344841==
//==1344841== HEAP SUMMARY:
//==1344841==     in use at exit: 0 bytes in 0 blocks
//==1344841==   total heap usage: 4 allocs, 4 frees, 1,072 bytes allocated
//==1344841==
//==1344841== All heap blocks were freed -- no leaks are possible
//==1344841==
//==1344841== For lists of detected and suppressed errors, rerun with: -s
//==1344841== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
