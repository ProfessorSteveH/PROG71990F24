#include "student.h"
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
	//STUDENT classroom[40]

	STUDENT steve = CreateStudent("steve", 12345678);

	PrintStudent(steve);

	DestroyStudent(steve);
	return 0;
}
