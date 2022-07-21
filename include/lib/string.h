#pragma once

#include <unistd.h>
#include <stdlib.h>

void *std_memcpy(void *dest, const void *src, size_t n);

void *std_memset(void *s, int c, size_t n);

char *std_strcat(char *dest, const char *src);

int std_strcmp(char *str1, char *str2);

int strncmp(const char *str1, const char *str2, size_t n);

char *std_strcpy(char *dest, const char *src);

char *std_strncpy(char *dest, const char *src, size_t n);

char *std_strdup(const char *src);

size_t std_strlen(const char *str);

size_t std_strnlen(const char *s, size_t maxlen);

size_t  std_strspn(const char *str, const char *accept);
