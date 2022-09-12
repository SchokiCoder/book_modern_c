#include <stdio.h>

#define HELLOWORLD_LEN 11
#define PRINT_LEN (HELLOWORLD_LEN + 4)

int main( void )
{
    char temp[4] = {'\0'};

    char arrfit[HELLOWORLD_LEN] = "Hello World";
    char arrmore[HELLOWORLD_LEN + 2] = "Hello World";
    const char *ptr = "Hello World";

    // print header
    printf("char | arrfit | arrmore | ptr\n");
    
    // for all characters
    for (unsigned int i = 0; i < PRINT_LEN; i++)
    {
        // if characters of all strings are equal
        if (arrfit[i] == arrmore[i] &&
            arrmore[i] == ptr[i])
        {
            // store actual character
            temp[0] = '\'';
            temp[1] = arrfit[i];
            temp[2] = '\'';
            temp[3] = '\0';
        }
        else
        {
            // store "NA"
            temp[0] = 'N';
            temp[1] = 'A';
            temp[2] = '\0';
        }

        // print cur character
        printf("%4s | %6i | %7i | %4i\n",
            temp, arrfit[i], arrmore[i], ptr[i]);
    }
}