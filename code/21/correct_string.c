/* ANCHOR: all */
#include <stdlib.h>
#include "string.h"

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

	self->size += len;
	self->str = realloc(self->str, sizeof(char) * self->size);

	/*
	   Here the wrong len value was used.
	   We needed the old String.len but used the len of the str.
	   This is also why String.len is getting updated later now.
	 */
	string_copy(&self->str[self->len], str, len);
	self->len += len;
}

// ANCHOR_END: String_append

void String_clear(struct String *self)
{
	self->size = 0;
	self->len = 0;
	free(self->str);
}

/* ANCHOR_END: all */
