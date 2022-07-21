#include "calcul_pos.h"

t_bunny_position calcul_pos(t_bunny_position pos, int width_img, int height_img)
{
    t_bunny_position pos_temp;

    pos_temp.x = pos.x + width_img / 2;
    pos_temp.y = pos.y + height_img / 2;
    return pos_temp;
}

t_bunny_pixelarray *hover(t_glob *glob, char *icon, char *icon_hover, int width_img, int height_img,
                          t_bunny_position pos)
{
    t_bunny_position pos_temp;
    t_bunny_pixelarray *img;

    pos_temp.x = pos.x + width_img / 2;
    pos_temp.y = pos.y + height_img / 2;

    if (verif_click(glob->mouse, pos_temp, width_img / 2, height_img / 2) == true)
        img = bunny_load_pixelarray(icon_hover);
    else
        img = bunny_load_pixelarray(icon);
    return img;
}

void gui(t_glob *glob)
{
    t_bunny_pixelarray *walk, *grab, *look;
    t_bunny_position pos_walk, pos_grab, pos_look, temp_pos;

    pos_walk.y = pos_grab.y = pos_look.y = 550;
    pos_walk.x = 0;
    pos_grab.x = 50;
    pos_look.x = 100;

    walk = hover(glob, "assets/game/walk.png", "assets/game/walk_hover.png", 50, 50, pos_walk);
    grab = hover(glob, "assets/game/grab.png", "assets/game/grab_hover.png", 50, 50, pos_grab);
    look = hover(glob, "assets/game/look.png", "assets/game/look_hover.png", 50, 50, pos_look);
    if (glob->graph_nbr == 5 && glob->stage_nbr == 1)
    {
        glob->check_show = true;
        look = bunny_load_pixelarray("assets/game/look_ready.png");
    }
    if (glob->graph_nbr == 2 && glob->stage_nbr == 3)
    {
        glob->check_show = true;
        look = bunny_load_pixelarray("assets/game/look_ready.png");
    }
    if (glob->graph_nbr == 3 && glob->stage_nbr == 2)
    {
        glob->check_show = true;
        look = bunny_load_pixelarray("assets/game/look_ready.png");
        if (glob->game_button == 3 && glob->taken == false)
        {
            grab = bunny_load_pixelarray("assets/game/grab_ready.png");
            temp_pos = calcul_pos(pos_grab, 50, 50);
            if (verif_click(glob->mouse, temp_pos, 25, 25) == true && glob->click == true)
            {
                if (glob->taken == false)
                {
                    t_bunny_music *take;
                    take = bunny_load_music("assets/gun.ogg");
                    take->sound.volume = glob->volume;
                    bunny_sound_play(&take->sound);
                    bunny_usleep(2e6);
                    bunny_delete_sound(&take->sound);
                    glob->taken = true;
                }
            }
        }
    }

    temp_pos = calcul_pos(pos_walk, 50, 50);
    if (verif_click(glob->mouse, temp_pos, 25, 25) == true && glob->click == true)
    {
        if (glob->game_button == 1)
            glob->game_button = 0;
        else
            glob->game_button = 1;
    }
    temp_pos = calcul_pos(pos_grab, 50, 50);
    // if (verif_click(glob->mouse, temp_pos, 25, 25) == true && glob->click == true)
    // glob->game_button = 2;
    temp_pos = calcul_pos(pos_look, 50, 50);
    if (verif_click(glob->mouse, temp_pos, 25, 25) == true && glob->click == true && glob->check_show == true)
        glob->game_button = 3;
    bunny_blit(&glob->screen.win->buffer, &walk->clipable, &pos_walk);
    bunny_blit(&glob->screen.win->buffer, &grab->clipable, &pos_grab);
    bunny_blit(&glob->screen.win->buffer, &look->clipable, &pos_look);
}
