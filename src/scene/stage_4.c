#include "stage.h"

static void screamer_anim(t_glob *glob)
{
    t_bunny_pixelarray *font, *end;
    t_bunny_position pos_text;
    char screamer[100] = "assets/screamer/frame_00_delay-0.07s.jpg";

    end = bunny_load_pixelarray("assets/stage_4/loose.png");
    font = bunny_load_pixelarray("assets/font.png");
    animation(glob, 20, screamer, "assets/screamer/screamer.ogg", 90000);
    pos_text.x = 250;
    pos_text.y = 500;
    std_text(end, font, pos_text, "Vous n'avez pas reussi a fuir", RED);
    pos_text.x = 300;
    pos_text.y = 520;
    std_text(end, font, pos_text, "La creature vous a tue", RED);
    bunny_blit(&glob->screen.win->buffer, &end->clipable, NULL);
    bunny_display(glob->screen.win);
    glob->stage_nbr = 6;
}

static void end(t_glob *glob)
{
    char image[100] = "assets/werewolf/frame_00_delay-0.1s.jpg";
    char screamer[100] = "assets/screamer/frame_00_delay-0.07s.jpg";
    if (glob->graph_nbr == 7)
    {
        glob->game_button = 0;
        t_bunny_pixelarray *end;
        t_bunny_pixelarray *font;
        t_bunny_position pos_text;
        font = bunny_load_pixelarray("assets/font.png");
        animation(glob, 15, image, "assets/werewolf/scream2.ogg", 70000);
        if (glob->taken == true)
        {
            end = bunny_load_pixelarray("assets/stage_4/win.png");
            pos_text.x = 150;
            pos_text.y = 500;
            std_text(end, font, pos_text, "Vous sortez votre pistolet et tirez sur la creature", RED);
            pos_text.x = 300;
            pos_text.y = 520;
            std_text(end, font, pos_text, "Vous avez elucide se mystere !", RED);
            bunny_blit(&glob->screen.win->buffer, &end->clipable, NULL);
            bunny_display(glob->screen.win);
            t_bunny_music *shot;
            shot = bunny_load_music("assets/gunshot.ogg");
            shot->sound.volume = glob->volume;
            bunny_sound_play(&shot->sound);
            bunny_usleep(2e6);
            bunny_delete_sound(&shot->sound);
            glob->stage_nbr = 6;
        }
        else
        {
            end = bunny_load_pixelarray("assets/stage_4/loose.png");
            animation(glob, 20, screamer, "assets/screamer/screamer.ogg", 90000);
            pos_text.x = 230;
            pos_text.y = 500;
            std_text(end, font, pos_text, "Vous n'avez pas de quoi vous defendre", RED);
            pos_text.x = 300;
            pos_text.y = 520;
            std_text(end, font, pos_text, "La creature vous a tue", RED);
            bunny_blit(&glob->screen.win->buffer, &end->clipable, NULL);
            bunny_display(glob->screen.win);
            glob->stage_nbr = 6;
        }
    }
}

void stage_4(t_glob *glob)
{
    t_bunny_pixelarray *plan;
    t_bunny_position pos_perso;
    int size = 5;
    static int first;

    plan = bunny_load_pixelarray("assets/stage_4/stage_4.png");
    glob->pic = plan;
    bunny_blit(&glob->screen.win->buffer, &plan->clipable, NULL);

    graph_stage_4(glob);
    t_node *node = glob->graph->array[1].head;
    t_node *node_wolf = glob->graph->array[7].head;
    pos_perso.x = node->pos.x;
    pos_perso.y = node->pos.y - 183 * size / 6 + 25;

    if (first == false)
        glob->pos_perso = pos_perso;

    size = size_selector(glob);

    pos_perso.y = node->pos.y - 183 * size / 6 + 25;
    if (first == false)
    {
        glob->graph_nbr = 1;
        glob->pos_wolf = node_wolf->pos;
        glob->pos_perso = pos_perso;
        glob->text = std_strcpy(glob->text, "Je dois atteindre la porte pour m'enfuire !");
        first = true;
    }

    click_graph(node, glob, size, 1, plan);
    click_graph(node, glob, size, 2, plan);
    click_graph(node, glob, size, 3, plan);
    click_graph(node, glob, size, 4, plan);
    click_graph(node, glob, size, 5, plan);
    click_graph(node, glob, size, 6, plan);
    click_graph(node, glob, size, 7, plan);
    print_text_box(glob, plan);

    idle_anim(glob, plan, glob->pos_perso, size);
    idle_anim_wolf(glob, glob->pos_wolf, size);
    if (glob->game_button == 1)
        print_graph(glob->graph, glob);
    if (glob->game_button == 3)
    {
        glob->game_button = 0;
    }
    gui(glob);

    bunny_display(glob->screen.win);
    bunny_delete_clipable(plan);
    if (glob->graph_nbr == glob->graph_wolf_nbr)
        screamer_anim(glob);
    end(glob);
}