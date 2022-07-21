/*                                                                                                                                                                                                   
** *****************************************************************************                                                                                                                     
** enzo.pfeiffer                                                                                                                                                                                     
** enzo.pfeiffer <enzo.pfeiffer@student-station>                                                                                                                                                     
**                                                                                                                                                                                                   
** vectrex_pixel.c - 2021                                                                                                                                                                            
**                                                                                                                                                                                                   
** *****************************************************************************                                                                                                                     
*/

#include "set_pixel.h"

void std_set_pixel(t_bunny_pixelarray *px,
		   t_bunny_position   pos,
		   unsigned int       color)
{
  int *pix;

  pix = px->pixels;
  if (pos.x >= 0 && pos.x < px->clipable.buffer.width &&
      pos.y >= 0 && pos.y < px->clipable.buffer.height)
    pix[px->clipable.buffer.width * pos.y + pos.x] = color;
}
