#include <stdio.h>
#include <stdlib.h>

// steveh - prog7199024 - week09 - in class

// command line args

int main(int argc, char** argv) {

	if (argc < 3) {
		fprintf(stderr, "usage: we need a command line param\n");
		exit(EXIT_FAILURE);
	}

	printf("hello %s %s\n", argv[1], argv[3]);

	return 0;
}