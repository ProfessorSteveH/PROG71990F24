// pointer to pointer use case #2
//       In C, the return value is often used for error handling or state information. Arguments are used for 
//       carrying the payload. One example: A function "returns" an address to newly allocated memory, but 
//       using an argument. You give the function a pointer to the pointer that should afterwards point to the 
//       data. The function overwrites that space and for that, it needs a pointer to a pointer.
//
// prog71990 - fall2024 - professor steveh

// this program works when configured as x86;


#include <stdio.h>
#include "network.h"

int main(void)
{
	byte* buffer;  // the problem is, you don't know how big your buffer will be....

	int numBytesRead = GetNetworkReceiveBuffer(&buffer); // here you get your buffer size and the buffer itself   (this models *alot* of lower level mechanisms)
	if (numBytesRead >= 0)	// we can have success even if there are no bytes to read!
	{
		// process our received data...
		printf("we have byte data to interact with:");
		for (byte i = 0; i < numBytesRead; i++)
		{
			printf("%c", *(buffer + i));		//print it out...
		}
		free(buffer);
	}
	else
		fprintf(stderr, "subsystem reports an error connecting to NetworkReceiveBuffer\n");
}
