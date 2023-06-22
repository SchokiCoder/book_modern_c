// include header stdio for printf
#include <stdio.h>

// main function
int main(void)
{
	// declare variables
	int i;
	int a = 1;
	int b = 1;
	int c = 1;

	// calculate 5th fibonacci number and print
	for (i = 0; i < 5; i++) {
		// save old b
		c = b;

		// save old a
		b = a;

		// calculate new a
		a = b + c;
	}

	// print result
	printf("fib num: %i\n", a);
}
