#pragma once

#include "clear_pixelarray.h"
#include "struct.h"
#include "text.h"
#include "type.h"

void animation(t_glob *glob, int nbr_frame, char *frame0, char *sound, int duration);

void anim_walk(t_glob *glob, t_bunny_pixelarray *dest, t_bunny_position pos_screen, int size, int frame,
               bool orientation, bool check_poto);

void anim_walk_wolf(t_glob *glob, t_bunny_pixelarray *dest, t_bunny_position pos_screen, int size, int frame,
                    bool orientation);

void idle_anim(t_glob *glob, t_bunny_pixelarray *dest, t_bunny_position pos_screen, int size);

void idle_anim_wolf(t_glob *glob, t_bunny_position pos_screen, int size);

void pegi_18(t_glob glob);
