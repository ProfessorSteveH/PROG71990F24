#include <stdio.h>
#include "student.h"
#include "professor.h"

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


	// prompt for student name
	char name[] = "steve";

	// prompt for student number
	int number = 12345678;

	STUDENT steve = CreateStudent(name, number);

	PrintStudent(steve);

	DestroyStudent(steve);

	//STUDENT classroom[CLASSROOM_CAPACITY] = { 0 };

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