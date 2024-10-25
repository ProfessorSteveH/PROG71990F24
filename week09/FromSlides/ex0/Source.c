#include <stdio.h>

// example 1 - pointers 

// PROG71990F24 - Oct 2024 - Professor SteveH

// revision history
//      1.0      2020-Jun-28          initial
//      1.1      2021-Jun-24          reviewed and updated
//      1.2      2022-May-20         reviewed
//		1.3		 2023-Jul			reviewed
//		1.4		 2024-Aug-25		reviewed

int main(void)
{
	int var1 = 24;	
	int var2 = 9;

	printf("%d %p\n", var1, &var1);  // &var1 == the memory address of var1 

	int* ptr = &var1;
	printf("%d %p\n", var1, ptr);

	ptr = &var2;
	printf("%d %p\n", var2, ptr);
}
