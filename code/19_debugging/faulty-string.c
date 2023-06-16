/* ANCHOR: all */
#include <stdlib.h>
#include "faulty_string.h"

String String_new()
{
    String result = {
        .size = STR_NEW_SIZE,
        .len = 0,
        .str = malloc(sizeof(char) * STR_NEW_SIZE),
    };
    
    return result;
}

String String_from( const char *str )
{
    size_t len = string_len(str);
    
    String result = {
        .size = len + 1,
        .len = len,
        .str = malloc(sizeof(char) * result.size),
    };
    
    string_copy(result.str, str, len);
    
    return result;
}

// ANCHOR: String_append
void String_append( String *self, const char *str)
{
    size_t len = string_len(str);
    
    self->len += len;
    self->size += len;
    self->str = realloc(
        self->str,
        sizeof(char) * self->size);
    
    string_copy(&self->str[len - 1], str, len);
}
// ANCHOR_END: String_append

void String_clear( String *self )
{
    self->size = 0;
    self->len = 0;
    free(self->str);
}
/* ANCHOR_END: all */
