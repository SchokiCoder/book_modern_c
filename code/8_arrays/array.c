#include <stdio.h>

int main( void )
{
    int i;
    int array[4];
    
    array[0] = 1;
    array[1] = 1;
    array[2] = 2;
    array[3] = 3;
    
    for (i = 0; i < 4; i++)
    {
        printf("i: %i; val: %i\n", i, array[i]);
    }
}