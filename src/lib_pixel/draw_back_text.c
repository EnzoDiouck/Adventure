#include "text.h"

void draw_back_text(t_bunny_pixelarray *px,
		      t_bunny_position pos,
		      unsigned int color)
{
  int oldx;
  int x;
  int y;
  
  oldx = pos.x;
  x = pos.x + 40;
  y = pos.y + 14;
  while(pos.x * pos.y < x * y)
    {
      if (pos.x == x)
	{
	  pos.x = oldx;
	  pos.y++;
	}
      std_set_pixel(px,pos,color);
      pos.x++;
    }
}
