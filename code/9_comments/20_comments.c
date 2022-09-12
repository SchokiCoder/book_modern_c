#include <stdio.h>

int main( void )
{
    int i;
    int a = 1;
    int b = 1;
    int c = 1;

    // calculate 5th fibonacci number and print
    for (i = 0; i < 5; i++)
    {
        c = b;
        b = a;
        a = b + c;
    }
    
    printf("fib num: %i\n", a);
}