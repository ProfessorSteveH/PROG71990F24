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

	CLASSROOM myClass = CreateClassroom("prog71990");

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