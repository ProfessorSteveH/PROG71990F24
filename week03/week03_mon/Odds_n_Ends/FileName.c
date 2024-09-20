#include <stdio.h>

// steveh - prog71990-f24 - week03

#define INCHES_TO_CM	2.54		// r-value

	
int main(void) {
	const float INCHES_TO_CM_CONST = 2.54f; //l-value
	// 1 bit - 1 or 0
	// 1 nibble - 4 bits  0000
	// 1 byte - 8 bits    0000 0000
	//  -->  ascii - 7 bit 127 printable (others not printable)
	// 2 bytes - word
	// 4 bytes - DWORD - 32 bits - 1 for sign, 31 for magnitude
	// 8 bytes - QWORD - 64 bits 

	size_t size = sizeof(int);  // we still use 32bits for int (even on 
								// 64bit platform)
	int i = 1; 
	i = i + 1;  //inc i
	i += 1;		//inc i
	i++;		//inc i

	i--;		//dec i

	i *= 2;		// take i and multiply it by 2 and store back in i


	i = 5;
	if (i-- == --i)   // => false
		// i-- => use, then decrement
		// --i => decrement, then use

		i = 7;   // place the value 5 in variable i

		// L-Value  -> a think that can hold a thing
		// R-Value  -> something that is not a l-value

		//const int  j = 7;	// const => a constant, 

		// j => unmodifiable l-value
		// i => modifiable l-value
		 
		// from previous example:
		//float inches = inputCM * INCHES_TO_CM;
		 
		//5 = i;

		// strong vs weak typing
		//	string => all variables have a type and types will match (C)
		//  float = float * string
		// weak is that variables have no type (or its implicit) (Javascript)

		// static typing v. dynamic typing
		//   => compile
		//     (java, c#)       => at runtime (python, javascript)

		float l = 3.14f;
		int k = l;			//implicit typecast
		int m = (int)l;		//explicit typecast 

		//i == 5	 // is the value in i equal to 5

	//looping

	//for(starting, exit condition, step function)
	//great for ranges (start and end are known)
	for (int i = 0; i < 6; i++) {
		printf("%d\n", i);  //prints 0,1,2,3,4,5 to the screen (one per line)
	}

	//while(should we continue) {
	// }


	int j = 10;
	// unknown exit condition (at the beginning), upto doing 0 iterations through the loop
	while (j < 9) {
		printf("%d\n", j++);
	}

	//do {
		// the body - the execution of program 
	//} while (exit condition);
	// unknown exit timing, but at least 1 time through the loop
	do {
		printf("%d\n", j++);
	} while (j < 9);

	int k = 0;
	while (1) {	// this is true - creating an endless loop
		if (k == 10)
			continue;
		printf("%d\n", k++);
	}

	// break and continue generally mean you have a flaw in your understanding
	// of the solution (or problem)
	// known as code smells => '

	// goto 
	int change_in_pocket = 125;

	int coin = 25;
	if (coin == 25) {
		printf("quarter\n");
	}
	else if (change_in_pocket < 100) {
		printf("pick up the coin\n");
	}
	else if (coin == 5) {
		printf("nickel\n");
	}
	else {
		printf("some other coin\n");
	


	switch (coin) {
		case 25: printf("this is a quarter\n");
				if (change_in_pocket < 125) {
					pick_up_coin();
					coin++;
				}
				 break;
		case 10: printf("this is a dime\n");
				 break;
		case 5:	 printf("this is a nickel\n");
				 break;
		default: printf("some other coin\n");
				 break;
	}

	return 0;
}
