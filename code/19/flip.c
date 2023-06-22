#include <stdio.h>

int main(void)
{
	unsigned int unflipped = 4000000000;
	signed int flipped = (signed int)unflipped;

	printf("%u flipped to %i\n", unflipped, flipped);
}
