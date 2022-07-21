/*
** *****************************************************************************
** enzo.pfeiffer
** enzo.pfeiffer <enzo.pfeiffer@student-station>
**
** main.c - 2021
**
** *****************************************************************************
*/

#include "clear_pixelarray.h"

void std_clear_pixelarray(t_bunny_pixelarray *picture, unsigned int color)
{
  int *pix;
  int i;

  pix = picture->pixels;
  i = 0;
  while(i < picture->clipable.buffer.width * picture->clipable.buffer.height)
    {
      pix[i] = color;
      i += 1;
    }
}
