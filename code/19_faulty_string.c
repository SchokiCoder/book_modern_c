/* ANCHOR: all */
#include <stdlib.h>
#include "19_string.h"

struct String String_new()
{
	struct String result = {
		.size = STR_NEW_SIZE,
		.len = 0,
		.str = malloc(sizeof(char) * STR_NEW_SIZE),
	};

	return result;
}

struct String String_from(const char *str)
{
	size_t len = string_len(str);

	struct String result = {
		.size = len + 1,
		.len = len,
		.str = malloc(sizeof(char) * result.size),
	};

	string_copy(result.str, str, len);

	return result;
}

// ANCHOR: String_append
void String_append(struct String *self, const char *str)
{
	size_t len = string_len(str);

	self->len += len;
	self->size += len;
	self->str = realloc(self->str, sizeof(char) * self->size);

	string_copy(&self->str[len - 1], str, len);
}

// ANCHOR_END: String_append

void String_clear(struct String *self)
{
	self->size = 0;
	self->len = 0;
	free(self->str);
}

/* ANCHOR_END: all */
