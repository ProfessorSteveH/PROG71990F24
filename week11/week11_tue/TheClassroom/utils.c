#include "utils.h"
#include <stdio.h>
#include <string.h>

// these are useful library functions for input

// steveh - prog71990-f24 - week06


void CleanNewLineFromString(char* Name) {
	for (int i = 0; i < strlen(Name); i++)
		if (Name[i] == '\n')
			Name[i] = '\0';
}