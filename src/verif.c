#include "verif.h"

bool verif_click(const t_bunny_position *pos_click, t_bunny_position pos, int x, int y)
{
  if (pos_click->x > pos.x - x &&
      pos_click->y > pos.y - y &&
      pos_click->x < pos.x + x &&
      pos_click->y < pos.y + y)
    return true;
  return false;
}
