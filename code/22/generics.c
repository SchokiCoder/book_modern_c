#include <stdio.h>

int addi(int a, int b)
{
        return a + b;
}

float addf(float a, float b)
{
        return a + b;
}

#define add(A, B) _Generic((A) + (B), \
        int: addi, \
        float: addf)(A, B)

int main(void)
{
        int a1 = 1, b1 = 2, c1;
        float a2 = 1.1, b2 = 1.5, c2;

        c1 = add(a1, b1);
        c2 = add(a2, b2);

        printf("int: %i, float: %f;\n", c1, c2);
}
