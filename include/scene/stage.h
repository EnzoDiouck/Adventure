#pragma once

#include "animation.h"
#include "blit.h"
#include "calcul_pos.h"
#include "graph_stage.h"
#include "parallax.h"
#include "set_line.h"
#include "string.h"

int size_selector(t_glob *glob);

void print_text_box(t_glob *glob, t_bunny_pixelarray *plan1);

void click_graph(t_node *node, t_glob *glob, int size, int node_nbr, t_bunny_pixelarray *plan1);

void click_graph_wolf(t_node *node, t_glob *glob, int size, int node_nbr, t_bunny_pixelarray *plan1);

void stage_0(t_glob *glob);

void stage_1(t_glob *glob);

void stage_2(t_glob *glob);

void stage_3(t_glob *glob);

void stage_4(t_glob *glob);
