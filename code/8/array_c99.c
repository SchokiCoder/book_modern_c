#include <stdio.h>

int main(void)
{
        int array[] = {
                [0] = 1,
                [1] = 1,
                [2] = 2,
                [3] = 3
        };
        int i;

        for (i = 0; i < 4; i++) {
                printf("i: %i; val: %i\n", i, array[i]);
        }

        return 0;
}
