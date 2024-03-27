#include <stdio.h>
#include <stdlib.h>

int main(void)
{
        /* OOPS, no malloc anymore. Teehee */
        int *ptr = NULL;

        *ptr = 7;

        printf("%li\n", sizeof(*ptr));

        free(ptr);
}
