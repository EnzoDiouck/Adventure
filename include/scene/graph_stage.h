#pragma once

#include "calcul_pos.h"
#include "graph.h"
#include "set_line.h"
#include "struct.h"

void graph_stage_1(t_glob *glob);
void graph_stage_2(t_glob *glob);
void graph_stage_3(t_glob *glob);
void graph_stage_4(t_glob *glob);
void print_graph(t_graph *graph, t_glob *glob);
t_bunny_position pos_perso_graph(t_glob *glob, int size);