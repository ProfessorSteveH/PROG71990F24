#include <stdio.h>
#include <string.h>

//week 05
// building 'bigger' things from smaller 'things'
// - arrays
//		- a set of the same type of things
//      - random access
//		- a set size (compile time)
// - strings
//		- an array of characters
//		- must end with '\0'
// - structs
// - enums

#define  INT_ARRAY_SIZE	5
#define  NAME_SIZE		20

int main(void) {

	int array[INT_ARRAY_SIZE] = { 0 };
	array[0] = 4;
	array[4] = 5;
	array[0] = 6;
	for(int i=0; i< INT_ARRAY_SIZE; i++)
		printf("%d\n", array[i]);


	//char letter = 's';				// a letter (of size 1)
	//char letter = "s";				// a "string" of size 2
	//char letter[] = { 's', '\0'};	// a "string" (of size 2)

	char name[] = {'s', 't', 'e', 'v', 'e', '\0'};	//not a string

	//printf("%s", name);
	for(int i=0; i< strlen(name); i++)
		printf("%c", name[i]);
	printf("\n");

	printf("%s\n", name);
		// arrays reduce to pointers

	char nameInput[NAME_SIZE] = { 0 };
	int returnItems = scanf("%s", nameInput);
	printf("%s\n", nameInput);

	// let's model a 'student' (
	//	- alive
	//	- backpack
	//  - close (proximity) to desk
	//	- uniform (clothing)
	//  - experience
	//	- at a school
	//	- person
	//	- name, student number
	//	- timetable

	// SOLID
	//	S - single respons
	//			coupling		-> for all students, student must have backpack
	//			cohesion		-> for all things student, the stuff within belongs

	// student 
		//	name
		//  student number

	return 0;
}