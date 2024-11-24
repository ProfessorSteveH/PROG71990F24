#pragma once
// pointer to pointer use case #2
//       In C, the return value is often used for error handling or state information. Arguments are used for 
//       carrying the payload. One example: A function "returns" an address to newly allocated memory, but 
//       using an argument. You give the function a pointer to the pointer that should afterwards point to the 
//       data. The function overwrites that space and for that, it needs a pointer to a pointer.
//
// prog71990 - fall2024 - professor steveh

#include <stdint.h>

typedef uint8_t byte;  //this is an unsigned int of size 8 --> perfect for a "byte" 

int GetNetworkReceiveBuffer(byte** buffer);
