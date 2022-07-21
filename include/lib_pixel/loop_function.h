#pragma once

#include "struct.h"
#include "menu.h"
#include "setting.h"
#include "play.h"

t_bunny_response loop_key(t_bunny_event_state state,
                          t_bunny_keysym keycode,
                          void *d);

bool verif_click(const t_bunny_position *pos_click, t_bunny_position pos, int x, int y);

t_bunny_response loop_move(const t_bunny_position *relative, void *d);

t_bunny_response loop_click(t_bunny_event_state state,
                            t_bunny_mouse_button button,
                            void *data);

t_bunny_response loop_function(void *d);
