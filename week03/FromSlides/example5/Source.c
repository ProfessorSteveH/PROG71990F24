//
// Week 3 - example5
//		spot the mistake #1
//
// PROG71990 - F24
// Professor SteveH - Sept 2024
//
// revision history
//		1.0		2020-May-28			initial
//      1.1      2021-May-27          reviewed and updated
//      1.2     2022-May-20         reviewed
//		1.3		  2023-Jul-19		reviewed
//		1.4		  2024-Aug-25		reviewed

#include <stdio.h>
int main(void)
{
    int n = 0;

    while (n < 3)
    {
        printf("n is %d\n", n);
        n++;
    }
    printf("That's all this program does\n");

    return 0;
}