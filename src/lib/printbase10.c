#include "type.h"

char *std_printbase10(int num)
{
    static char rpz[] = "0123456789";
    static char buf[50];
    char *ptr;

    ptr = &buf[49];
    *ptr = '\0';
    while (num != 0)
    {
        *--ptr = rpz[num % 10];
        num /= 10;
    }
    return (ptr);
}
