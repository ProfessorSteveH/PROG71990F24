#include <stdio.h>
#include <stdlib.h>
#include "student.h"
#include "professor.h"
#include "participant.h"
#include "classroom.h"

#define CLASSROOM_CAPACITY	40

// model a school
//   college
//     - department
//          - program
//              - courses
//                  - section 
//                       - class (a specific room and time and topic)
//                            - room
//                            - professor
//                            - students
//                            - guests


// steveh - prog71990-f24 - week10

int main(void) {

	CLASSROOM myClass = CreateClassroom("prog71990", 35);

	STUDENT newStudent = CreateStudent("billy", 1234);
	if (!AddParticipantToClassroom(&myClass, CreateParticipantFromStudent(newStudent))) {
		fprintf(stderr, "error\n");
		exit(EXIT_FAILURE);
	}
	DestroyStudent(newStudent);

	PROFESSOR newProf = CreateProfessor("steveh", "acsit");
	if (!AddParticipantToClassroom(&myClass, CreateParticipantFromProfessor(newProf))) {
		fprintf(stderr, "error\n");
		exit(EXIT_FAILURE);
	}

	PrintClassroom(myClass);
	if (!WriteClassroomToFile(myClass, "classroom.dat")) {
		fprintf(stderr, "error writing classroom to disk\n");
	}

	printf("------\n");

	RemoveParticipantFromClassroom(&myClass, CreateParticipantFromProfessor(newProf));
	//PrintClassroom(myClass);

	printf("------\n");
	CLASSROOM newClass = { 0 };


	if (!ReadClassroomFromFile(&newClass, "classroom.dat")) {
		fprintf(stderr, "failed to read classroom file\n");
	}
	else {
		printf("we are here\n");
		PrintClassroom(newClass);
		DestroyClassroom(newClass);
	}

	// make sure not to use newCLass unless it was 
	// successfully opened
	DestroyClassroom(myClass);


	//PARTICIPANT classroom[40] = { 0 };
	////classroom[0] = Create 

	//// prompt for student name
	//char name[] = "steve he";

	//// prompt for student number
	//int number = 12345678;

	//STUDENT steve = CreateStudent(name, number);

	//WriteStudentToFile(steve, "student.dat");

	//STUDENT newStudent = ReadStudentFromFile("student.dat");
	//PrintStudent(newStudent);

	//PrintStudent(steve);

	//DestroyStudent(steve);


	//typedef struct classroom {
	//	int capacity;
	//	char location[20];
	//	STUDENT classroom[capacity];
	//} CLASSROOM;

;

	// prompt for student number
	//char dept[] = "acsit"; 

	//PROFESSOR prof = CreateProfessor(name, dept);

	//PrintProfessor(prof);

	//DestroyProfessor(prof);


	//return 0;
}

//$ make valgrind
//valgrind --tool=memcheck --leak-check=yes --show-reachable=yes --num-callers=20 --track-fds=yes ./main
//==3644521== Memcheck, a memory error detector
//==3644521== Copyright (C) 2002-2022, and GNU GPL'd, by Julian Seward et al.
//==3644521== Using Valgrind-3.22.0 and LibVEX; rerun with -h for copyright info
//==3644521== Command: ./main
//==3644521==
//Classroom: prog71990
//PROFESSOR: steveh, acsit
//STUDENT: billy, 1234
//------
//------
//we are here
//Classroom: prog71990
//STUDENT: billy, 1234
//PROFESSOR: steveh, acsit
//==3644521==
//==3644521== FILE DESCRIPTORS: 3 open (3 std) at exit.
//==3644521==
//==3644521== HEAP SUMMARY:
//==3644521==     in use at exit: 0 bytes in 0 blocks
//==3644521==   total heap usage: 9 allocs, 9 frees, 18,800 bytes allocated
//==3644521==
//==3644521== All heap blocks were freed -- no leaks are possible
//==3644521==
//==3644521== For lists of detected and suppressed errors, rerun with: -s
//==3644521== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
