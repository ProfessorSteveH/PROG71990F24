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

	CLASSROOM myClass = CreateClassroom("programming principles");

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

	DestroyClassroom(myClass);

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
