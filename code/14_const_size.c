#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	const unsigned int ARR_LEN = 20;
	int *array = malloc(ARR_LEN * sizeof(int));

	for (unsigned int i = 0; i < ARR_LEN; i++) {
		printf("i: %i, val: %i;\n", i, array[i]);
	}

	free(array);
}
