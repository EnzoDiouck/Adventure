#pragma once

#include <stddef.h>
#include <stdlib.h>

char **std_split(char *str, char token);

int std_atoi(const char *str);

char *std_printbase10(int num);
