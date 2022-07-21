#pragma once

#include "verif.h"

t_bunny_position calcul_pos(t_bunny_position pos, int width_img, int height_img);

t_bunny_pixelarray *hover(t_glob *glob, char *icon, char *icon_hover, int width_img, int height_img, t_bunny_position pos);

void gui(t_glob *glob);
