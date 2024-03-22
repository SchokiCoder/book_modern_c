#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
        const long unsigned str_size = 20;
        char *str = malloc(str_size);

        if (argc <= 1) {
                fprintf(stderr, "String is not given.\n");
                goto cleanup;
        }

        if (strlen(argv[1]) > str_size) {
                fprintf(stderr, "String is too big.\n");
                goto cleanup;
        }

        strncpy(str, argv[1], str_size);
        printf("Tha string: \"%s\"\n", str);

cleanup:
        free(str);

        printf("Ze end.\n");

        return 0;
}
