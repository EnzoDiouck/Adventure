#include "text.h"

void std_letter(t_bunny_pixelarray *pix,
		t_bunny_pixelarray *font,
		t_bunny_position pos,
		char c,
		unsigned int color)
{
  t_bunny_position pos_font;
  int oldposx;
  unsigned int color2;
  
  pos_font.y = 0;
  oldposx = pos.x;
  while (pos_font.y <= 13)
    {
      pos_font.x = c * 10;
      pos.x = oldposx;
      while(pos_font.x < (c*10 + 10))
	{
	  color2 = std_get_pixel(font,pos_font);
	  if (color2 == PINK2)
	    {
	      color2 = color;
	      std_set_pixel(pix,pos,color2);
	    }
	  pos.x++;
	  pos_font.x++;
	}
      pos.y++;
      pos_font.y++;
    }
}
