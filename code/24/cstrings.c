#include <stdio.h>

#define HELLOWORLD "Hello World"
#define HELLOWORLD_LEN 11
#define PRINT_LEN (HELLOWORLD_LEN + 4)

int main(void)
{
        const char arrfit[HELLOWORLD_LEN] = HELLOWORLD;
        const char arrmore[HELLOWORLD_LEN + 2] = HELLOWORLD;
        const char *ptr = HELLOWORLD;
        unsigned int i;
        char temp[4] = { '\0' };

        printf("char | arrfit | arrmore | ptr\n");

        for (i = 0; i < PRINT_LEN; i++) {
                // if characters of all strings are equal, print char, else NA
                if (arrfit[i] == arrmore[i] && arrmore[i] == ptr[i]) {
                        temp[0] = '\'';
                        temp[1] = arrfit[i];
                        temp[2] = '\'';
                        temp[3] = '\0';
                } else {
                        temp[0] = 'N';
                        temp[1] = 'A';
                        temp[2] = '\0';
                }

                printf("%4s | %6i | %7i | %4i\n",
                       temp, arrfit[i], arrmore[i], ptr[i]);
        }
}
