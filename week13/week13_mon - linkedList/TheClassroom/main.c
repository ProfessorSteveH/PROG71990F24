#include "student.h"
#include "professor.h"
#include "participant.h"
#include "classroom.h"
#include <stdio.h>
#include <stdlib.h>


// prog71990-f24 - week10 - steveh

// modelling a school
//     locations
//         departments
//           programs
//              courses
//                sections
//                   classes
//                       -time
//                       -topic
//                       -room
//                          -capacity (40)
//                          - student
//                          - professor
//                          - guest

int main(void) {

	CLASSROOM myClass = CreateClassroom("programming principles", 35);

	PROFESSOR myProf = CreateProfessor("stevehe", "acsit");

	if (!AddProfessorToClassroom(&myClass, myProf)) {
		fprintf(stderr, "error adding prof to class\n");
		exit(EXIT_FAILURE);			//this needs future attention
	}

	STUDENT myStudent = CreateStudent("billy", 1234);

	if (!AddStudentToClassroom(&myClass, myStudent)) {
		fprintf(stderr, "error adding student to class\n");
		exit(EXIT_FAILURE);
	}

	DestroyStudent(myStudent);

	PrintClassroom(myClass);
	WriteClassroomToFile(myClass, "classroom.dat");

	DestroyClassroom(myClass);

	CLASSROOM newClass = { 0 };
	if (ReadClassroomFromFile(&newClass, "classroom.dat")) {
		PrintClassroom(newClass);
        DestroyClassroom(newClass);
	}
	else {
		fprintf(stderr, "unable to open file\n");
		exit(EXIT_FAILURE);
	}

	//PARTICIPANT classroom[40] = { 0 };

	////classroom[0] = Create

	//STUDENT steve = CreateStudent("steve", 12345678);
	//WriteStudentToFile(steve, "student.dat");

	//STUDENT readFromFile = ReadStudentFromFile("student.dat");

	//PrintStudent(readFromFile);

	//PrintStudent(steve);

	//DestroyStudent(steve);

	//PROFESSOR profSteve = CreateProfessor("steve", "acsit");

	//PrintProfessor(profSteve);

	//DestroyProfessor(profSteve);


	return 0;
}

//$ make valgrind
//valgrind --tool=memcheck --leak-check=yes --show-reachable=yes --num-callers=20 --track-fds=yes ./main
//==3645105== Memcheck, a memory error detector
//==3645105== Copyright (C) 2002-2022, and GNU GPL'd, by Julian Seward et al.
//==3645105== Using Valgrind-3.22.0 and LibVEX; rerun with -h for copyright info
//==3645105== Command: ./main
//==3645105==
//CLASS NAME: programming principles
//STUDENT: billy, 1234
//PROFESSOR: stevehe, acsit
//CLASS NAME: programming principles
//PROFESSOR: stevehe, acsit
//STUDENT: billy, 1234
//==3645105==
//==3645105== FILE DESCRIPTORS: 3 open (3 std) at exit.
//==3645105==
//==3645105== HEAP SUMMARY:
//==3645105==     in use at exit: 0 bytes in 0 blocks
//==3645105==   total heap usage: 9 allocs, 9 frees, 18,800 bytes allocated
//==3645105==
//==3645105== All heap blocks were freed -- no leaks are possible
//==3645105==
//==3645105== For lists of detected and suppressed errors, rerun with: -s
//==3645105== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
