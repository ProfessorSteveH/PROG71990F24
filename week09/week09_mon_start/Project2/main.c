#include <stdio.h>

// steveh - prog71990f24 - week09

// "arrays reduce to pointers"

void function(int* array, int max_size) {
	for (int i = 0; i < max_size; i++)
		printf("%d\n", *(array + i));
}


int main(void) {

	int array[] = { 1,2,3,4 };

	printf("%d\n", array[0]);
	printf("%d\n", *array);

	printf("%d\n", array[1]);
	for(int i=0; i< 4; i++)
		printf("%d\n", *(array+i));

	function(array, 4);

	return 0;
}