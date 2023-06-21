#include <stdint.h>
#include <stdio.h>

int main()
{
	int32_t i;
	uint32_t u;
	
	printf("ALWAYS 32 bits (4 bytes): %li, %li\n", sizeof(i), sizeof(u));
}
