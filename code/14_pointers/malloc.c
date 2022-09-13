#include <stdio.h>
#include <stdlib.h>

int main( void )
{
    int* ptr = malloc(sizeof(int));
    
    *ptr = 7;

    printf("%li\n", sizeof(*ptr));

    free(ptr);
}