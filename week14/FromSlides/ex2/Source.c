// pointers to functions
//
// prog71990 - fall 2024 - professor steveh
//
#include <stdio.h>
#include <stdlib.h>
#include "student.h"


//according to the textbook, you should always use void* for your
//comparison function for qsort:
int compareProperlyByStudentNumber(const void* A, const void* B) {
	// casting the void* to STUDENT*:
	return (  ((STUDENT*)A)->studentnum - ((STUDENT*)B)->studentnum  );
}

//but my experience has always been that just a simple cast in the 
//function definition is enough:
int compareByStudentNumberFunction(const STUDENT* a, const STUDENT* b)
{
	return (a->studentnum - b->studentnum);
}


int compareByStudentNameFunction(const STUDENT* a, const STUDENT* b)
{
	return (a->name[0] - b->name[0]);
}

int main(void)
{
	STUDENT classList[] = {
		createStudent("Harry", 3234),
		createStudent("Zoey", 1234),
		createStudent("Abigail", 9234),
		createStudent("Rhonda", 7234),
		createStudent("Charlie", 2234)
	};

	printf("Sorted by Student Number:\n");
	qsort(classList, sizeof(classList) / sizeof(STUDENT), sizeof(STUDENT), compareByStudentNumberFunction);

	for (int i = 0; i < sizeof(classList) / sizeof(STUDENT); i++)
		printStudent(classList[i]);

	printf("\n\nSorted by Student Name:\n");
	qsort(classList, sizeof(classList) / sizeof(STUDENT), sizeof(STUDENT), compareByStudentNameFunction);
	for (int i = 0; i < sizeof(classList) / sizeof(STUDENT); i++)
		printStudent(classList[i]);

	printf("\n\nAnd now using a compare function with void* pointers (by number):\n");
	qsort(classList, sizeof(classList) / sizeof(STUDENT), sizeof(STUDENT), compareProperlyByStudentNumber);

	for (int i = 0; i < sizeof(classList) / sizeof(STUDENT); i++)
		printStudent(classList[i]);
}
