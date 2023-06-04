#ifndef CORRECT_STRING_H
#define CORRECT_STRING_H

#include "string_utils.h"

static const size_t STR_NEW_SIZE = 8;

typedef struct String
{
    size_t size;
    size_t len;
    char *str;
} String;

String String_new();

String String_from( const char *str );

void String_append( String *self, const char *str);

void String_clear( String *self );

#endif /* CORRECT_STRING_H */