#include "stage.h"

void click_graph_wolf(t_node *node, t_glob *glob, int size, int node_nbr, t_bunny_pixelarray *plan1)
{
    t_bunny_position temp_pos, old_pos, vector, draw;
    double coef = 0.0;
    bool in_dest = false;
    static int frame = 1;
    static int slow;
    bool poto = false;

    node = glob->graph->array[node_nbr].head;
    t_node *temp_node = node;
    temp_pos = calcul_pos(node->pos, 50, 50);
    if (verif_click(glob->mouse, temp_pos, 25, 25) == true && glob->click == true)
    {
        // printf("node = %d\n", node_nbr);
        while (temp_node != NULL)
        {
            if (temp_node->dest == glob->graph_nbr)
                in_dest = true;
            temp_node = temp_node->next;
        }
        if (in_dest == false)
        {
            glob->text = std_strcpy(glob->text, "Le chemin est trop long !");
            return;
        }
        t_bunny_music *foot;
        int orientation = true;
        foot = bunny_load_music("assets/foot_grass.ogg");
        foot->sound.volume = glob->volume;
        bunny_sound_play(&foot->sound);
        int old_size = size;
        old_pos.x = glob->pos_perso.x;
        old_pos.y = glob->pos_perso.y + 183 * size / 6;
        size = size_selector(glob);
        glob->pos_perso.y = node->pos.y + 25;
        glob->pos_perso.x = node->pos.x + 25;
        vector.x = glob->pos_perso.x - old_pos.x;
        vector.y = glob->pos_perso.y - old_pos.y;
        size = size_selector(glob);
        if (old_pos.x < old_pos.x + vector.x)
            orientation = false;
        while (coef < 1)
        {
            if (slow == 10)
            {
                slow = 0;
                frame++;
            }
            if (frame == 8)
                frame = 1;
            draw.x = old_pos.x + vector.x * coef;
            draw.y = old_pos.y + vector.y * coef;
            if (glob->stage_nbr == 3)
                poto = true;
            (void)poto;
            anim_walk_wolf(glob, plan1, draw, old_size, frame, orientation);
            coef += 0.01;
            slow++;
        }
        size = size_selector(glob);
        if (size > old_size)
            glob->pos_perso.y = node->pos.y - 183 * old_size / 6;
        else
            glob->pos_perso.y = node->pos.y - (183 * size / 6) + 25;
        glob->pos_perso.x = node->pos.x + 25;
        size = size_selector(glob);
        if (size > old_size)
            glob->pos_perso.y = node->pos.y - 183 * old_size / 6;
        else
            glob->pos_perso.y = node->pos.y - (183 * size / 6) + 25;
        glob->pos_perso.x = node->pos.x + 25;
        glob->graph_nbr = node_nbr;
        bunny_delete_sound(&foot->sound);
    }
}