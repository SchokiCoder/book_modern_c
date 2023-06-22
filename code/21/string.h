#ifndef _STRING_H
#define _STRING_H

#include "string_utils.h"

static const size_t STR_NEW_SIZE = 8;

struct String {
	size_t size;
	size_t len;
	char *str;
};

struct String String_new();

struct String String_from(const char *str);

void String_append(struct String *self, const char *str);

void String_clear(struct String *self);

#endif				/* _STRING_H */
