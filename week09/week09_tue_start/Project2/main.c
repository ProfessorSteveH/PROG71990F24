#include <stdio.h>

// prog71990-f24 - steveh - week09

// arrays reduce to pointers

void function(int* array, int size) {

	for (int i = 0; i < size; i++)
		printf("%d\n", *(array + i));


}

int main(void) {

	int array[] = { 1,2,3,4 };

	printf("%d\n", array[0]);
	printf("%d\n", *array);

	printf("%d\n", array[1]);
	printf("%d\n", *(array+1));

	function(array, 4);

	return 0;
}