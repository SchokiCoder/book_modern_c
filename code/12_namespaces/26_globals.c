#include <stdio.h>

int a = 2, c = 0;

int triple( int b )
{
    a *= 3;
    return a;
}

int main( void )
{
    c = triple(a);

    printf("a: %i c: %i\n", a, c);
}