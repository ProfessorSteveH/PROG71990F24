// prog71990 - week4 - pass by value - Professor SteveH - fall 2024

// revision history
//		1.0		2020-June-10			initial
//     1.1      2021-May-27          reviewed and updated
//      1.2     2022-May-20         reviewed
//		1.3		  2023-Jul-19		reviewed
//		1.4		  2024-Aug-25		reviewed

#include <stdio.h>

void increment(int a)
{
	a = a + 1;
}

int main(void)
{
	int q = 3;
	float r = 1.0f;
	int z = 5;
	printf("%d\n", z);
	increment(z);
	printf("%d\n", z);
}