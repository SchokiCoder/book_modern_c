#include <stdio.h>

void intptr(int *ptr)
{
        *ptr = 6;
}

int main(void)
{
        int myint = 1;

        printf("%i\n", myint);

        intptr(&myint);

        printf("%i\n", myint);
}
