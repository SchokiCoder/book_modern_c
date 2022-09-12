#include <stdlib.h>

int main( void )
{
    unsigned int i;
    int *ptr = malloc(sizeof(int));
    
    *ptr = 7;
    
    for (i = 0; i < 10; i++)
    {
        *ptr *= 2;
    }
    
    free(ptr);
}