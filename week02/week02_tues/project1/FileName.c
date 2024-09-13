#define _CRT_SECURE_NO_WARNINGS

// write a program to translate inches to cm.  get the inches from the 
// user and print the cm to the screen

// steveh - prog71990 - week1 - fall24

#include <stdio.h>

#define CM_IN_INCHES		2.54
#define NOT_VALID_INPUT		1
#define NOT_VALID_NUMBER	2

int main(void) {

	//input
	// introduce the program 
	printf("please enter your height in inches: ");

	// take user input (in inches)
	float inputInches;

//#define idiomatic 1

#ifdef idiomatic
	//one way to take advantage of all the power of C (in an idiomiatic fashion)
	if (!(scanf("%f", &inputInches) == 1 && inputInches > 0)) {
		printf("that input is not allowed\n");
		return NOT_VALID_INPUT;
	}
#else
	//another option - sequential, one problem at a time (and this is ok too!)
	int items = scanf("%f", &inputInches);   // we use & in front of variable when input is 
	if (items != 1) {					 // numeric
		printf("that input is not allowed\n");
		return NOT_VALID_INPUT;
	}
	if( inputInches <= 0 ) {		// a height of 0 or less is preposterous
		printf("that input is not allowed\n");
		return NOT_VALID_NUMBER;
	}
#endif

	//transform
	float outputCM = inputInches * CM_IN_INCHES;

	//output
	// print the height in cm to the screen 
	printf("your height, in cm, is: %f\n", outputCM);

	return 0;
}

