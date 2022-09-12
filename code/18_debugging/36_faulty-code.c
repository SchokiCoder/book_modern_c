#include "faulty_string.h"
#include <stdio.h>

int main( void )
{
    String str_hi = String_from("hi");
    String str_twoplusone = String_new();
    
    String_append(&str_twoplusone, "two");
    String_append(&str_twoplusone, " + ");
    String_append(&str_twoplusone, "one");
    
    printf(
        "1: %s\n2: %s\nquick math\n",
        str_hi.str,
        str_twoplusone.str);
    
    String_clear(&str_hi);
    String_clear(&str_twoplusone);
    
    return 0;
}