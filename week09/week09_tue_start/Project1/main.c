#include <stdio.h>
#include <stdlib.h>

// prog71990-f24 - steveh - week09 in class

#define REQUIRED_ARG_COUNT		6

int main(int argc, char** argv) {  // array of strings (char*)

	if (argc != 5) {
		fprintf(stderr, "usage: %s -f <solutionname> -cmd <command>\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	for (int i = 0; i < REQUIRED_ARG_COUNT; i++)
		printf("%s\n", argv[i]);

	return 0;
}