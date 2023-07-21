#include <stdio.h>

int triple(int b)
{
        a *= 3;
        return a;
}

int main(void)
{
        int a = 2, c = 0;
        c = triple(a);

        printf("a: %i c: %i\n", a, c);
}
