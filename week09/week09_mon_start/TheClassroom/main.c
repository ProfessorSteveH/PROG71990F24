#include "student.h"
#include "professor.h"
#include "participant.h"
#include <stdio.h>

// prog71990-f24 - week05 - steveh

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

	PARTICIPANT classroom[40] = { 0 };

	//classroom[0] = Create

	STUDENT steve = CreateStudent("steve", 12345678);
	WriteStudentToFile(steve, "student.dat");

	STUDENT readFromFile = ReadStudentFromFile("student.dat");

	PrintStudent(readFromFile);

	PrintStudent(steve);

	DestroyStudent(steve);

	PROFESSOR profSteve = CreateProfessor("steve", "acsit");

	PrintProfessor(profSteve);

	DestroyProfessor(profSteve);


	return 0;
}
