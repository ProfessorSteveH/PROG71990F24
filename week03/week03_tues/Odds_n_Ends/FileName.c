#include <stdio.h>

// week 3 some misc. topics

// steveh - prog71990-f24 - week03

#define CM_IN_INCHES		2.54		// a symbol

int main(void) {

	const float CM_IN_INCHES_CONST = 2.54f;		//use const like this

	int i = 0;   // single = => assignment
	//(  a == 4 ) // double equals means evaluation: is a equal to 4?

	size_t size = sizeof(int);

	// 1 bit => smallest => 0 or 1
	// 4 bits => nibble
	// 8 bits => byte,    ASCII = 7 bit encoding (wasting 1 bit)
	// 16 bits => WORD
	// 32 bits => DWORD
	// 64 bits => QWORD

	i = i + 1;
	i += 1;			//2nd form of previous line
	i++;			//3rd form of previous line
					// means "use then increment"

	i *= 2;			// multiply i by 2 and store back into i
	i = i * 2;		// same

	++i;			// increment then use
	if (i++ == ++i)
		printf("true\n");		//this wont compile, but it is illustrative

	const int j = 6;
	//5 = i;	//obviously won't work
	//L-Value => a thing that can hold a thing (modifiable and unmodifiable)
	//R-Value => anything that is not an l-value

	float inchesHeight;
	float cmHeight = inchesHeight * CM_IN_INCHES;  //which are lvalues?

	int j = cmHeight;  //implicit typecasting - maybe unintended side effects
	int k = (int)cmHeight;  //explicit typecasting (preferred)
			// why did you truncate => the topic of your comment

	//strong typing v. weak typing
	//  strong => all variables have a type
	//  weak => variables have an implied type
	//       eg:  a = 5
	//            b = 3.14
	//            c = a + b;
	// static typing v. dynamic typing
	//  => checks are during compile
	//					=> dynamic means checks are done at runtime.

	//for (starting condition; exit condition; advancement condition) {
	//for loops are great for defined ranges
	for(int h=0; h < 6; h++) {
		printf("%d\n", h);		//will print 0,1,2,3,4,5 (one on each line)
	}

	int w = 10;
//	while (should we continue?) {
	// while loops run 0 or more times
	while(w < 6) {
		printf("%d\n", w++);
	}

	printf("----\n");
	printf("%d\n", w);

	// do...while is guaranteed to run at least 1 time
	do {
		printf("%d\n", w++);
		//this is our repeated code
	} while (w < 10);


	int t = 5;
	while (1) {
		if (t == 10)
			continue;
		printf("%d\n", t++);


		//body
	}

	int q = 25;
	if (q == 25) {
		printf("it's a quarter\n");
	}
	else if (q == 10) {
		printf("it's a dime\n");
	}
	else {
		printf("it's some other coin\n");
	}

	switch (q) {
	case 25:	printf("it's a quarter\n");
				break;
	case 10:	printf("it's a dime\n");
				break;
	case 5:		printf("it's a nickel\n");
				break;
	case 1:		printf("it's a penny\n");
				break;
	default:	printf("it's some other coin\n");
				break;
	}

	return 0;
}