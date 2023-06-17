#ifndef _19_STRING_UTILS_H
#define _19_STRING_UTILS_H

typedef unsigned long size_t;

size_t string_len(const char *str);

void string_copy(char *restrict dest, const char *restrict src, size_t len);

#endif				/* _19_STRING_UTILS_H */
