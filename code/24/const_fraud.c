#include <stdio.h>

const int CONSTI = 10;

int main()
{
	int *i = (int*) &CONSTI;
	*i = 5;

	printf("%i\n", CONSTI);
	return 0;
}
