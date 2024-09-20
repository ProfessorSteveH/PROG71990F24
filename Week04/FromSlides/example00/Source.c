//
// Week 4 - example0
//		textbook example 0 - using functions with arguments
//
// PROG71990 - F24
// Professor SteveH - Sept 2024
//
// revision history
//		1.0		2020-June-10			initial
//      1.1      2021-May-27          reviewed and updated
//      1.2     2022-May-20         reviewed
//		1.3		  2023-Jul-19		reviewed
//		1.4		  2024-Aug-25		reviewed

#include <stdio.h>

//void pound(int n);   // ANSI function prototype declaration
void pound(int);


int main(void)
{
    int times = 5;
    char ch = '!';   // ASCII code is 33
    float f = 6.0f;

    pound(times);    // int argument
    pound(ch);        // same as pound((int)ch);
    pound(f);          // same as pound((int)f);

    return 0;
}

void pound(int n)    // ANSI-style function header
{                             // says takes one int argument
    while (n-- > 0)
        printf("#");
    printf("\n");
}