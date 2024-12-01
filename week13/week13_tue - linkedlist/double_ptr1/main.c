#include <stdio.h>

int main(int argc, char** argv) {
	if (argv[0][1] == *(argv[0] + sizeof(char)))
		printf("matched\n");

	return 0;
}