#include "19_string_utils.h"

size_t string_len(const char *str)
{
	size_t result = 0;

	while (str[result] != '\0')
		result++;

	return result;
}

void string_copy(char *restrict dest, const char *restrict src, size_t len)
{
	for (size_t i = 0; i < len; i++) {
		dest[i] = src[i];
	}
}
