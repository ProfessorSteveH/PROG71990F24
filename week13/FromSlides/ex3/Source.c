// pointers to pointers use case #1
// project -> properties -> config properties -> debugging -> command arguments = first second
//
// prog71990 - fall 2024 - professor steveh


#include <stdio.h>
#include <stdlib.h> //for exit()

int main(int argc, char** argv)	// argv = "an array of pointers to strings"
{
	if (argc < 2)
	{
		fprintf(stderr, "no good.  we need at least 2 params\n");
		exit(1);
	}

	printf("zero-th param: %s\n", *(argv + 0));			//this is the first level pointer (each points to first char of C string)
	char* nextLevel = *(argv + 0);
	printf("second level of zeroth first level: %c\n", *(nextLevel + 9));   // should be 'S' (on my path - yours will be different!)
	// or
	printf("second level of zeroth first level: %c\n", *(*(argv + 0) + 9));   // should be 'S' (on my path - yours will be different!)


	//another example, the one-th param:
	printf("one-th param: %s\n", *(argv + 1));			//this is the first level pointer (each points to first char of C string)
	nextLevel = *(argv + 1);
	printf("second level of zeroth first level: %c\n", *(nextLevel + 2));   // should be 'r'  from "first"
	// or
	printf("second level of zeroth first level: %c\n", *(*(argv + 1) + 2));   // should be 'r' from "first"

	return 0;
}
