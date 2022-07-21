#include "text.h"

void std_text(t_bunny_pixelarray *pix, t_bunny_pixelarray *font, t_bunny_position pos, const char *str,
              unsigned int color)
{
    int comp;

    comp = 0;
    while (str[comp] != '\0')
    {
        std_letter(pix, font, pos, str[comp], color);
        comp++;
        pos.x += 10;
    }
}