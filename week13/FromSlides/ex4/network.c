// pointer to pointer use case #2
//       In C, the return value is often used for error handling or state information. Arguments are used for 
//       carrying the payload. One example: A function "returns" an address to newly allocated memory, but 
//       using an argument. You give the function a pointer to the pointer that should afterwards point to the 
//       data. The function overwrites that space and for that, it needs a pointer to a pointer.
//
// prog71990 - fall2024 - professor steveh

#include "network.h"

int GetNetworkReceiveBuffer(byte** buffer)
{
	int bufferSize = 123;				// i am simulating some lower level function that has given me the number of bytes on the wire to read 
	*buffer = malloc(bufferSize * sizeof(byte));
	if (!buffer)
		return -1;		//-1 means an error!
	else
	{
		memset(*buffer, 'A', bufferSize);
		return bufferSize;
	}
}
