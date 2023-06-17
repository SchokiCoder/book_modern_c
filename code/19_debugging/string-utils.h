#ifndef STRING_UTILS_H
#define STRING_UTILS_H

typedef unsigned long size_t;

size_t string_len(const char *str);

void string_copy(char *restrict dest, const char *restrict src, size_t len);

#endif				/* STRING_UTILS_H */
