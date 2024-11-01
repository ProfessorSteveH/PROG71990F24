#include "student.h"
#include <stdio.h>
#include <stdlib.h>

// prog71990-f24 - steveh - week09 - the heap!

int main(int argc, char** argv) {

	if (argc != 3) {
		fprintf(stderr, "usage: %s <student_name> <student_number>\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	PSTUDENT s = CreateStudent(argv[1], atoi(argv[2]));
	if (s == NULL) {
		fprintf(stderr, "could not create student, exiting...\n");
		exit(EXIT_FAILURE);
	}

	PrintStudent(s);

	DestroyStudent(s);

	return 0;
}