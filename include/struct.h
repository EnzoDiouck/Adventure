#pragma once

#include "graph.h"
#include <lapin.h>

typedef struct s_setting
{
    t_bunny_pixelarray *background;
    t_bunny_pixelarray *volume, *up_arrow, *down_arrow, *back_arrow;
    t_bunny_position pos_volume, pos_up_arrow, pos_down_arrow, pos_back_arrow;
} t_setting;

typedef struct s_menu
{
    t_bunny_pixelarray *background;
    t_bunny_pixelarray *start, *setting, *exit;
    t_bunny_position pos_start, pos_setting, pos_exit;
} t_menu;

typedef struct s_screen
{
    t_bunny_window *win;
    t_bunny_pixelarray *pic;
} t_screen;

typedef struct s_glob
{
    int volume;
    t_bunny_music *music;
    const t_bunny_position *mouse;
    bool click;
    t_screen screen;
    t_menu menu;
    t_graph *graph;
    int game_button;
    t_bunny_position pos_perso;
    t_bunny_position pos_wolf;
    int graph_nbr;
    int graph_wolf_nbr;
    int stage_nbr;
    char *text;
    bool check_show;
    bool taken;
    int tuto;
    t_bunny_pixelarray *pic;
} t_glob;
