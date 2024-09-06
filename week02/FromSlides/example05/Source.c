//
// An example #5
//		mapping variables to formatted printf.
//
// PROG71990 - F24
// Professor SteveH- Sept 2024
//
// revision history
//		1.0		2020-Apr-28			initial	
//      1.1       2021-May-15         reviewed/updated
//      1.2     2022-May-20         reviewed
//		1.3		  2023-Jul-19		reviewed
//		1.4		  2024-Aug-25		reviewed

#include <stdio.h>

int main(void)
{
	int n = 4;
	int m = 5;
	float f = 7.0f;
	float g = 8.0f;

	printf("%d\n", n, m);   // one format specifier and two variables
	printf("%d %d %d\n", n);  //three format specifiers and one variable
	printf("%d %d\n", f, g); // wrong type for format specifier.

	return 0;  //no errors
}