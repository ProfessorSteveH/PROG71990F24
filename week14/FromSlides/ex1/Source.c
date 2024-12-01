// pointers to functions
//
// prog71990 - fall 2024 - professor steveh
//
#include "simpleMath.h"
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>  //for _getch() - i don't actually know why i used this function!

int main(void)
{
	int a = 0, b = 0;
	int (*mathOper)(int, int);		// declare our 'function' variable
	char o;

	printf("enter a: ");
	scanf("%d", &a);
	printf("enter b: ");
	scanf("%d", &b);
	printf("enter operatior (+,-,*,/,%%): ");
	o = _getch();
	switch (o)
	{
	case '+':	mathOper = add2Ints;
		break;
	case '-':	mathOper = subtract2Ints;
		break;
	case '*':	mathOper = multiply2Ints;
		break;
	case '/':	mathOper = divide2Ints;
		break;
	case '%':	mathOper = modulus2Ints;
		break;
	default:	printf("\n%c: thats not a valid option\n", o);
		return 1;
		break;
	}
	int answer = mathOper(a, b);
	printf("\nanswer for %c is: %d\n", o, answer);
	return 0;
}
