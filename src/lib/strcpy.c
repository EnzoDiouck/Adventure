#include "string.h"

char *std_strcpy(char *dest,
		 const char *src)
{
  int comp;

  comp = 0;
  while (src[comp] != '\0')
    {
      dest[comp] = src[comp];
      comp++;
    }
  dest[comp] = '\0';
  return dest;
}
