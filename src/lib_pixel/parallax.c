#include "parallax.h"

t_bunny_accurate_position parallax(t_glob *glob)
{
  t_bunny_accurate_position center, result;
  
  center.x = glob->screen.win->buffer.width / 2;
  center.y = glob->screen.win->buffer.height / 2;

  result.x =  ((glob->mouse->x - center.x) / glob->screen.win->buffer.width) * 2;//ici je dois avoir une valeur qui va de 0 a 100
  result.y =  ((glob->mouse->y - center.y) / glob->screen.win->buffer.height) * 2;//ici aussi voir feuille

  
  result.x += 1;
  result.y += 1;
  return result;
}
