
/* ----- NON CANONICAL CODE AHEAD ----- */

/*
#include <stdbool.h>

#include "intstuff.h"
#include "floatstuff.h"

int add(int a, int b)
{
    return a + b;
}
*/

/*
#include <stdio.h>

int main() {
    short a = 2147483647;
    printf("%i\n", a);
}
*/

    /*int sum = add(10, 5);
    printf("%i\n", sum);*/

/*
    int num = 0;

    switch (num)
    {
        case 0:
            num = 1;
            break;

        case 1:
            num = 0;
            break;

        case 7:
            num *= 3;
            break;

        case 43:
            num = -1;
            break;

        case 68:
            num++;
            break;

        case 101:
            num /= 2;
            break;
    }

    return 0;
*/
/*
    int num = 22;
    bool num_even = false;
    bool something_is_not_right = false;

    if ((num % 2) == 0)
    {
        num_even = true;
    }

    if (num == 23 && num_even)
    {
        something_is_not_right = true;
    }
*/

/*
    printf("f: %f\n", floatadd(0.1, 0.4));
*/

/*
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

size_t stringlen( const char *str )
{
    size_t result = 0;

    while (str[result] != '\0')
        result++;

    return result + 1;
}

void stringcpy( char *restrict dest, const char *restrict src, size_t len )
{
    for (size_t i = 0; i < len; i++)
    {
        dest[i] = src[i];
    }

    dest[len - 1] = '\0';
}

typedef struct String
{
    char *str;
    size_t size;
    size_t len;
} String ;

String String_new( const size_t inital_size )
{
    String result = {
        .str = malloc(inital_size),
        .len = 0,
        .size = inital_size
    };

    return result;
}

void String_ensure_size( String *str, size_t size )
{
    while (str->size < size)
        str->size *= 2;
    
    str->str = realloc(str->str, str->size);
}

void String_append( String *dest, char *addendum )
{
    size_t add_len = stringlen(addendum);
    
    String_ensure_size(dest, dest->len + add_len);

    stringcpy(&dest->str[dest->len], addendum, add_len);

    dest->len += add_len;
}

void String_clear( String *str )
{
    free(str->str);
    str->len = 0;
    str->size = 0;
}

void String_debug( String *str )
{
    printf("stringdbg:\tstr  %p\n\t\tlen  %lu\n\t\tsize %lu\n",
        str->str, str->len, str->size);
    printf("content: {\n");

    for (size_t i = 0; i < str->size; i++)
    {
        printf("\t\t%c %i\n", str->str[i], str->str[i]);
    }

    printf("}\n");
}

int main( void )
{
    String intro = String_new(20);
    String_append(&intro, "Hello World,");
String_debug(&intro);
    String_append(&intro, " i am a string.");
String_debug(&intro);
    
    printf("%s\n", intro.str);
String_debug(&intro);
    String_clear(&intro);
}*/


/*
#include <stdio.h>

int main( void )
{
    long int li = 10000000000;
    int i = li;

    printf("%li to %i\n", li, i);
}
*/

/*
#include <stdio.h>
#include <string.h>

#define BUF_MAXLEN 20

char buffer[BUF_MAXLEN];
char password[BUF_MAXLEN] = "andyspword";

int main(int argc, char **argv)
{
    if (argc != 3)
    {
        printf("Please provide a password and a secret\n");
        return 0;
    }
    
    strcpy(buffer, argv[2]);
    
    if (strcmp(argv[1], password) == 0)
        printf("My darkest secret is %s\n", buffer);
    else
        printf("Password incorrect\n");
    
    return 0;
}
*/

























































