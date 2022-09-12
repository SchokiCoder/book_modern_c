#include <stdio.h>
#include <string.h>

void reverse1(
    const char *src,
    char* dest,
    unsigned int len )
{
    for (unsigned int i = 0; i < len; i++)
    {
        dest[i] = src[len - i - 1];
    }

    dest[len] = '\0';
}

void reverse2( char *str )
{
    unsigned int len = strlen(str);
    
    for (unsigned int i = 0; i < len / 2; i++)
    {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}

int main( void )
{
    char str1[20] = "F for Jacob Sorber";
    char str2[20];

    reverse1(str1, str2, strlen(str1));

    printf("method 1: \"%s\" copy to \"%s\"\n", str1, str2);

    reverse2(str1);

    printf("method 2: \"%s\"\n", str1);
}