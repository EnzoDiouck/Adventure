#pragma once

#include "set_pixel.h"

void draw_back_text(t_bunny_pixelarray *px, t_bunny_position pos, unsigned int color);

unsigned int std_get_pixel(t_bunny_pixelarray *px, t_bunny_position pos);

void std_letter(t_bunny_pixelarray *pix, t_bunny_pixelarray *font, t_bunny_position pos, char c, unsigned int color);

void std_text(t_bunny_pixelarray *pix, t_bunny_pixelarray *font, t_bunny_position pos, const char *str,
              unsigned int color);