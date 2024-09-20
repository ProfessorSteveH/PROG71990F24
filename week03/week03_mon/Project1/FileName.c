#define _CRT_SECURE_NO_WARNINGS

// take a number from user, convert it from inches to cm and display to the user

// steveh - prog71990 - fall24 - week02

#include <stdio.h>

#define  CM_PER_INCH					2.54
#define  INVALID_INPUT					1
#define  INVALID_INPUT_LESS_THAN_ZERO	2

int main(void) {

	//input
	printf("please enter your height in inches: ");
	float inputInches;	
	int symbolsConverted = scanf("%f", &inputInches);  // & infront of variables of number type
	if (symbolsConverted != 1) {		// ! => not
		printf("your input is invalid\n");
		return INVALID_INPUT;
	}
	if (inputInches <= 0) {
		printf("your input is invalid (less than zero)\n");
		return INVALID_INPUT_LESS_THAN_ZERO;
	}

	//process
	float outputCM = inputInches * CM_PER_INCH;

	//output
	printf("you gave %f inches and your height in cm is: %f\n",
				inputInches, outputCM);

	return 0;  // 0 is good (success)
}