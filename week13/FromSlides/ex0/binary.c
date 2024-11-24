// recursion - why use it ever???
// based on 9.8 from text
// prog71990 - fall 2024 - professor steveh
//

#include "binary.h"

void to_binary(unsigned long n)
{
	int r;
	r = n % 2;
	if (n >= 2)
		to_binary(n / 2);
	putchar(r == 0 ? '0' : '1');
	return;
}
