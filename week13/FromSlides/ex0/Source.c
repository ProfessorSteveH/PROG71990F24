// some refresh on bits, AND and OR and XOR
//
// prog71990 - fall 2024 - professor steveh
//
// i borrowed binary.c and binary.h from week12 -> what excellent reuse!

#include <stdio.h>
#include <stdint.h>
#include "binary.h"

int main(void)
{										//  0000 0000	
	// first AND
	uint8_t  numA = 133;
	to_binary(numA);
	printf("\n    ");

	uint8_t numB = 13;
	to_binary(numB);
	printf("\n---------AND\n     ");

	uint8_t anded = numA & numB;
	to_binary(anded);
	printf("\n\n\n");

	// and now OR
	to_binary(numA);
	printf("\n    ");
	to_binary(numB);
	printf("\n---------OR\n");

	uint8_t ored = numA | numB;
	to_binary(ored);
	printf("\n\n\n");

	// and now XOR
	to_binary(numA);
	printf("\n    ");
	to_binary(numB);
	printf("\n---------XOR\n");

	uint8_t xored = numA ^ numB;
	to_binary(xored);
	printf("\n\n");
}
