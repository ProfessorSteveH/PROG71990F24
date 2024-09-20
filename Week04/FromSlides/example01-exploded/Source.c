#include <stdio.h>
#include "maths.h"

// an "exploded" version of the last example.
// this separates the utility functions (into a 'library') separate from the main program
// prog71990 - fall 2024 - Professor SteveH

// revision history
//		1.0		2020-June-10			initial
//      1.1      2021-May-27          reviewed and updated
//      1.2     2022-May-20         reviewed
//		1.3		  2023-Jul-19		reviewed
//		1.4		  2024-Aug-25		reviewed

int main(void)
{
    double x, xpow;
    int exp;

    printf("Enter a number and the positive integer power");
    printf(" to which\nthe number will be raised. Enter q");
    printf(" to quit.\n");
    while (scanf_s("%lf%d", &x, &exp) == 2)
    {
        xpow = power(x, exp);   // function call
        xpow = sqrt(x);
        printf("%.3g to the power %d is %.5g\n", x, exp, xpow);
        printf("Enter next pair of numbers or q to quit.\n");
    }
    printf("Hope you enjoyed this power trip -- bye!\n");

    return 0;
}