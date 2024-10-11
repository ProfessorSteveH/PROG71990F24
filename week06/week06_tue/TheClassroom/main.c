#include <stdio.h>
#include "student.h"
#include "professor.h"
#include "participant.h"

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


// steveh - prog71990-f24 - week05

int main(void) {

	PARTICIPANT classroom[40] = { 0 };
	//classroom[0] = Create 

	// prompt for student name
	char name[] = "steve he";

	// prompt for student number
	int number = 12345678;

	STUDENT steve = CreateStudent(name, number);

	WriteStudentToFile(steve, "student.dat");

	STUDENT newStudent = ReadStudentFromFile("student.dat");
	PrintStudent(newStudent);

	PrintStudent(steve);

	DestroyStudent(steve);


	//typedef struct classroom {
	//	int capacity;
	//	char location[20];
	//	STUDENT classroom[capacity];
	//} CLASSROOM;

;

	// prompt for student number
	char dept[] = "acsit"; 

	PROFESSOR prof = CreateProfessor(name, dept);

	PrintProfessor(prof);

	DestroyProfessor(prof);


	return 0;
}