#pragma once

#include <lapin.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct s_node
{
    int dest;
    t_bunny_position pos;
    struct s_node *next;
} t_node;

typedef struct s_list
{
    t_node *head;
} t_list;

typedef struct s_graph
{
    int v;
    t_list *array;
} t_graph;

t_graph *create_graph(int v);
t_node *new_node(int dest, t_bunny_position pos);
void add(t_graph *graph, int src, int dest, t_bunny_position pos);
void free_graph(t_graph *graph);