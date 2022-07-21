#include "graph_stage.h"
#include "stage.h"

void print_graph(t_graph *graph, t_glob *glob)
{
    t_bunny_clipable *red;
    t_bunny_position pos[2];

    red = bunny_load_picture("assets/game/red.png");
    int i = 1;
    while (i < graph->v)
    {
        t_node *node, *temp_node, *aaa;

        node = graph->array[i].head;
        pos[0].x = node->pos.x + 25;
        pos[0].y = node->pos.y + 25;
        aaa = node;
        while (aaa != NULL)
        {
            temp_node = graph->array[aaa->dest].head;
            pos[1].x = temp_node->pos.x + 25;
            pos[1].y = temp_node->pos.y + 25;
            std_set_line(glob->pic, pos, RED);
            aaa = aaa->next;
        }
        i++;
    }
    bunny_blit(&glob->screen.win->buffer, &glob->pic->clipable, NULL);
    i = 1;
    while (i < graph->v)
    {
        t_node *node;

        node = graph->array[i].head;
        bunny_blit(&glob->screen.win->buffer, red, &node->pos);
        i++;
    }
    if (glob->stage_nbr == 4)
        idle_anim_wolf(glob, glob->pos_wolf, 0);
}

void graph_stage_1(t_glob *glob)
{
    t_graph *graph = create_graph(7);
    t_bunny_position pos;

    pos.x = 734;
    pos.y = 500;
    add(graph, 1, 1, pos);
    pos.x = 665;
    pos.y = 332;
    add(graph, 1, 2, pos);
    pos.x = 710;
    pos.y = 210;
    add(graph, 2, 3, pos);
    pos.x = 662;
    pos.y = 176;
    add(graph, 3, 4, pos);
    pos.x = 350;
    pos.y = 325;
    add(graph, 3, 5, pos);
    pos.x = 559;
    pos.y = 152;
    add(graph, 4, 6, pos);
    glob->graph = graph;
}

void graph_stage_2(t_glob *glob)
{
    t_graph *graph = create_graph(5);
    t_bunny_position pos;

    pos.x = 197;
    pos.y = 530;
    add(graph, 1, 1, pos);
    pos.x = 480;
    pos.y = 440;
    add(graph, 1, 2, pos);
    pos.x = 770;
    pos.y = 386;
    add(graph, 2, 3, pos);
    pos.x = 360;
    pos.y = 360;
    add(graph, 2, 4, pos);
    glob->graph = graph;
}

void graph_stage_3(t_glob *glob)
{
    t_graph *graph = create_graph(4);
    t_bunny_position pos;

    pos.x = 197;
    pos.y = 530;
    add(graph, 1, 1, pos);
    pos.x = 183;
    pos.y = 430;
    add(graph, 1, 2, pos);
    pos.x = 516;
    pos.y = 417;
    add(graph, 2, 3, pos);
    glob->graph = graph;
}

void graph_stage_4(t_glob *glob)
{
    t_graph *graph = create_graph(8);
    t_bunny_position pos;

    pos.x = 750;
    pos.y = 550;
    add(graph, 1, 1, pos);
    pos.x = 640;
    pos.y = 460;
    add(graph, 1, 3, pos);
    pos.x = 420;
    pos.y = 550;
    add(graph, 1, 2, pos);

    pos.x = 550;
    pos.y = 520;
    add(graph, 1, 4, pos);
    pos.x = 420;
    pos.y = 550;
    add(graph, 4, 2, pos);
    pos.x = 190;
    pos.y = 490;
    add(graph, 2, 5, pos);
    pos.x = 400;
    pos.y = 440;
    add(graph, 5, 6, pos);
    pos.x = 190;
    pos.y = 490;
    add(graph, 3, 6, pos);
    pos.x = 140;
    pos.y = 400;
    add(graph, 5, 7, pos);
    pos.x = 140;
    pos.y = 400;
    add(graph, 6, 7, pos);

    glob->graph = graph;
}