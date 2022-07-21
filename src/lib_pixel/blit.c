#include "blit.h"

void std_myblit(t_glob *glob, t_bunny_pixelarray *dest, t_bunny_pixelarray *src, int ban, t_bunny_position pos2, t_bunny_accurate_position para)
{
  t_bunny_position pos;
  int color, color2;
  t_bunny_position old_pos2;

  pos.x = pos.y = 0;
  pos2.x *= para.x;
  pos2.y *= para.y;
  old_pos2 = pos2;
  while (pos.x * pos.y < glob->screen.win->buffer.width * glob->screen.win->buffer.height)
    {
      if (pos.x == glob->screen.win->buffer.width)
	{
	  pos.x = 0;
	  pos2.x = old_pos2.x;
	  pos.y++;
	  pos2.y++;
	}
      color = std_get_pixel(dest, pos);
      color2 = std_get_pixel(src, pos2);
      if (color == ban)
	std_set_pixel(dest, pos, color2);
      pos.x++;
      pos2.x++;
    }
}

void covert(t_glob *glob, t_bunny_pixelarray *pic, int ban)
{
  t_bunny_position pos;
  int color;

  pos.x = pos.y = 0;
  while (pos.x * pos.y < glob->screen.win->buffer.width * glob->screen.win->buffer.height)
    {
      if (pos.x == glob->screen.win->buffer.width)
	{
	  pos.x = 0;
	  pos.y++;
	}
      color = std_get_pixel(pic, pos);
      if (color == ban)//if (color >= ban - 100 && color <= ban + 100)
	{
	  pos.x--;
	  if (pos.x < 0)
	    {
	      pos.y--;
	      pos.x = glob->screen.win->buffer.width;
	    }
	  //printf("%d et %d\n",pos.x,pos.y);
	  color = std_get_pixel(pic, pos);
	  pos.x++;
	  std_set_pixel(pic, pos, color);	  
	}
      //else
	pos.x++;
    }
}
