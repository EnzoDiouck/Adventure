#include "stage.h"

static void show_hidden_2(t_glob *glob)
{
    t_bunny_pixelarray *back, *back_arrow;
    t_bunny_clipable *gun;
    t_bunny_position pos, pos_back_arrow, pos_temp;

    pos.x = 300;
    pos.y = 100;
    pos_back_arrow.x = 750;
    pos_back_arrow.y = 536;
    back = bunny_load_pixelarray("assets/stage_2/grass.jpg");
    gun = bunny_load_picture("assets/stage_2/gun.png");
    back_arrow = hover(glob, "assets/back_arrow.png", "assets/back_arrow_hover.png", 150, 64, pos_back_arrow);
    pos_temp = calcul_pos(pos_back_arrow, 150, 64);
    if (verif_click(glob->mouse, pos_temp, 75, 32) == true && glob->click == true)
        glob->game_button = 0;
    pos_temp = calcul_pos(pos_back_arrow, 50, 50);
    bunny_blit(&glob->screen.win->buffer, &back->clipable, NULL);
    bunny_blit(&glob->screen.win->buffer, &back_arrow->clipable, &pos_back_arrow);
    if (glob->taken == false)
    {
        bunny_blit(&glob->screen.win->buffer, gun, &pos);
        glob->text = std_strcpy(glob->text, "Je devrais le prendre, il pourrait peut etre me servir.");
    }
    print_text_box(glob, back);
    gui(glob);
    bunny_display(glob->screen.win);
}

void stage_2(t_glob *glob)
{
    t_bunny_pixelarray *plan1, *plan2;
    t_bunny_accurate_position para;
    t_bunny_position pos, pos_perso;
    int size = 5;
    static int first;

    plan2 = bunny_load_pixelarray("assets/stage_2/background3.png");
    plan1 = bunny_load_pixelarray("assets/stage_2/stage_2.png");
    para = parallax(glob);
    pos.x = 5;
    pos.y = 5;
    std_myblit(glob, plan1, plan2, -12693146, pos, para);
    glob->pic = plan1;
    bunny_blit(&glob->screen.win->buffer, &plan1->clipable, NULL);

    graph_stage_2(glob);
    t_node *node = glob->graph->array[1].head;
    pos_perso.x = node->pos.x;
    pos_perso.y = node->pos.y - 183 * size / 6 + 25;
    if (first == false)
        glob->pos_perso = pos_perso;

    size = size_selector(glob);

    pos_perso.y = node->pos.y - 183 * size / 6 + 25;
    if (first == false)
    {
        glob->graph_nbr = 1;
        glob->pos_perso = pos_perso;
        first = true;
    }

    click_graph(node, glob, size, 1, plan1);
    click_graph(node, glob, size, 2, plan1);
    click_graph(node, glob, size, 3, plan1);
    click_graph(node, glob, size, 4, plan1);

    print_text_box(glob, plan1);
    idle_anim(glob, plan1, glob->pos_perso, size);
    if (glob->game_button == 1)
        print_graph(glob->graph, glob);
    if (glob->game_button == 3)
        show_hidden_2(glob);
    gui(glob);

    bunny_display(glob->screen.win);
    bunny_delete_clipable(plan2);
    bunny_delete_clipable(plan1);
    if (glob->graph_nbr == 4)
        glob->stage_nbr = 3;
}