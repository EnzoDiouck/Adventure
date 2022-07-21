#include "stage.h"

void stage_0(t_glob *glob)
{
    t_bunny_pixelarray *bg, *font, *tuto;
    t_bunny_position pos_text;
    static bool test = false;

    std_clear_pixelarray(glob->screen.pic, BLACK);
    font = bunny_load_pixelarray("assets/font.png");
    if (test == false)
    {
        pos_text.x = 300;
        pos_text.y = 300;
        std_text(glob->screen.pic, font, pos_text, "Press [SPACE] to continu the TUTO", RED);
        bunny_blit(&glob->screen.win->buffer, &glob->screen.pic->clipable, NULL);
        bunny_display(glob->screen.win);
        bunny_usleep(2e6);
        test = true;
    }
    if (glob->tuto == 0)
    {
        tuto = bunny_load_pixelarray("assets/stage_0/Intro.png");
        bunny_blit(&glob->screen.win->buffer, &tuto->clipable, NULL);
        bunny_display(glob->screen.win);
    }
    else if (glob->tuto == 1)
    {
        tuto = bunny_load_pixelarray("assets/stage_0/Tuto_1.png");
        bunny_blit(&glob->screen.win->buffer, &tuto->clipable, NULL);
        bunny_display(glob->screen.win);
    }
    else if (glob->tuto == 2)
    {
        tuto = bunny_load_pixelarray("assets/stage_0/Tuto_2.png");
        bunny_blit(&glob->screen.win->buffer, &tuto->clipable, NULL);
        bunny_display(glob->screen.win);
    }
    else if (glob->tuto == 3)
    {
        tuto = bunny_load_pixelarray("assets/stage_0/Tuto_3.png");
        bunny_blit(&glob->screen.win->buffer, &tuto->clipable, NULL);
        bunny_display(glob->screen.win);
    }
    else if (glob->tuto == 4)
    {
        pos_text.x = 350;
        pos_text.y = 500;
        bg = bunny_load_pixelarray("assets/stage_0/start.jpg");
        std_text(bg, font, pos_text, "Vous arrivez proche du lieux.", RED);
        pos_text.x = 150;
        pos_text.y = 520;
        std_text(bg, font, pos_text, "Vous descendez de votre voiture et continuez votre chemin a pieds.", RED);
        bunny_blit(&glob->screen.win->buffer, &bg->clipable, NULL);
        bunny_display(glob->screen.win);
        bunny_usleep(5e6);
        glob->stage_nbr = 1;
    }
    else
        glob->tuto = 0;
}

int size_selector(t_glob *glob)
{
    int size;
    if (400 < glob->pos_perso.y)
        size = 5;
    else if (200 < glob->pos_perso.y && 400 > glob->pos_perso.y)
        size = 3;
    else
        size = 2;
    return size;
}

void click_graph(t_node *node, t_glob *glob, int size, int node_nbr, t_bunny_pixelarray *plan1)
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
        if (node_nbr == glob->graph_wolf_nbr)
        {
            glob->text = std_strcpy(glob->text, "La creature bloque le chemin !");
            return;
        }
        t_bunny_music *foot;
        int orientation = true;
        if (glob->stage_nbr < 3)
            foot = bunny_load_music("assets/foot_grass.ogg");
        else
            foot = bunny_load_music("assets/foot_castle.ogg");
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
            anim_walk(glob, plan1, draw, old_size, frame, orientation, poto);
            coef += 0.01;
            slow++;
        }
        if (glob->stage_nbr == 4)
        {
            int dest[6];
            int j = 1;
            t_node *node_wolf = glob->graph->array[glob->graph_wolf_nbr].head;
            old_pos = node_wolf->pos;
            temp_node = node_wolf;
            while (temp_node != NULL)
            {
                dest[j] = temp_node->dest;
                temp_node = temp_node->next;
                j++;
            }
            int test = rand() % j;
            if (test == 0)
                test = 1;
            glob->graph_wolf_nbr = dest[test];
            node_wolf = glob->graph->array[glob->graph_wolf_nbr].head;
            glob->pos_wolf = node_wolf->pos;
            vector.x = glob->pos_wolf.x - old_pos.x;
            vector.y = glob->pos_wolf.y - old_pos.y;
            coef = 0.0;
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
                if (glob->stage_nbr == 4)
                    anim_walk_wolf(glob, plan1, draw, size, frame, orientation);
                coef += 0.01;
                slow++;
            }
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

void print_text_box(t_glob *glob, t_bunny_pixelarray *plan1)
{
    t_bunny_position pos_text;
    static int second;
    t_bunny_pixelarray *font = bunny_load_pixelarray("assets/font.png");

    pos_text.x = 151;
    pos_text.y = 585;
    if (second < 60)
    {
        std_text(plan1, font, pos_text, glob->text, RED);
        second++;
    }
    else
    {
        second = 0;
        glob->text = std_memset(glob->text, 0, 100);
    }
}