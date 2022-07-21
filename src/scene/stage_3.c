#include "stage.h"

void stage_3(t_glob *glob)
{
    t_bunny_pixelarray *plan;
    t_bunny_position pos_perso;
    int size = 5;
    static int first;
    static bool anim = false;
    char image[100] = "assets/howling/frame_00_delay-0.09s.jpg";

    plan = bunny_load_pixelarray("assets/stage_3/stage_3.jpg");
    glob->pic = plan;
    bunny_blit(&glob->screen.win->buffer, &plan->clipable, NULL);

    graph_stage_3(glob);
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

    click_graph(node, glob, size, 1, plan);
    click_graph(node, glob, size, 2, plan);
    click_graph(node, glob, size, 3, plan);

    print_text_box(glob, plan);
    idle_anim(glob, plan, glob->pos_perso, size);
    if (glob->game_button == 1)
        print_graph(glob->graph, glob);
    if (glob->game_button == 3)
    {
        if (anim == false)
        {
            animation(glob, 20, image, "assets/howling/howling.ogg", 90000);
            glob->game_button = 0;
            anim = true;
        }
        else
            glob->text = std_strcpy(glob->text, "La CHOSE vient de s'enfuire !");
    }
    gui(glob);

    bunny_display(glob->screen.win);
    bunny_delete_clipable(plan);
    if (glob->graph_nbr == 3)
        glob->stage_nbr = 4;
}