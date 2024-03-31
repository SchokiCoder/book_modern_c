#include <stdbool.h>
#include <stdio.h>
#include <string.h>

bool verify_arg(const char *str)
{
        if (strlen(str) != 2)
                return false;

        if (str[0] != '-')
                return false;

        switch (str[1]) {
        case 'A': /* fallthrough */ 
        case 'h':
        case 'z':
        case 'Z':
                break;

        default:
                return false;
        }

        return true;
}

int main(int argc, char *argv[])
{
        int i;
        bool all_args_valid = true;

        if (argc < 2) {
                printf("No arguments given.\n");
                return 0;
        }

        for (i = 1; i < argc; i += 1)
                if (verify_arg(argv[i]) == true)
                        printf("Arguments[%i]: \"%s\" is valid.\n", i, argv[i]);
                else
                        all_args_valid = false;

        if (all_args_valid == false)
                printf("Not all arguments are valid :(\n");

        return 0;
}
