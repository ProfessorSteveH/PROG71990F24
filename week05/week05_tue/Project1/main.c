#include <stdio.h>
#include <string.h>

//week 05
// building 'bigger' things from smaller 'things'
// - arrays ->  collection of '_____'
//	 - random access 
//	 - fixed size 
//	 - all elements in the array must be the same type (int, float, char)
// - strings
//   - an array of chars
//   - must end with '\0' (null, termininator, 0x00)
// - structs
// - enums

#define INT_ARRAY_SIZE	6
#define INPUT_MAX		40

int main(void) {

	int array[INT_ARRAY_SIZE] = { 0 };
	array[0] = 4;
	int value = array[0];

	//for (int i = 0; i < INT_ARRAY_SIZE; i++)
	//	printf("element is %d\n", array[i]);


	int array2[INT_ARRAY_SIZE] = { 1, 2, 3, 4 };	// elements 4,5 are not init'ed
	for (int i = 0; i < INT_ARRAY_SIZE; i++)
		printf("element is %d\n", array2[i]);

	char letter = 's';
	char letters = "s";  // this is a string
						 // { 's', '\0' };
	char name[] = { 's', 't', 'e', 'v', 'e' }; // not a string
	printf("%s\n", name);
	for (int i = 0; i < strlen(name); i++)	// strlen is not happy!
		printf("%c", name[i]);
	printf("\n");

	char userInput[INPUT_MAX] = { 0 };
	int recieved = scanf("%s", userInput);
	printf("%s\n", userInput);

	int size = 6;
	int array3[size]; // in VS, array size must be RValue.  
	// unless not using VS. 
	//		for other compilers, aka CLion => VLA, they allow lvalue as size
	//		if you use CLion, this is the reason we define language as C99

	// let's model a school
	// we can start with a student
	// first identify the smallest common characteristics
	// - student number
	// - name










	return 0;
}