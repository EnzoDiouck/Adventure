#include "menu.h"

static void menu_view(t_glob *glob)
{
    glob->menu.pos_start.x = glob->menu.pos_setting.x = glob->menu.pos_exit.x = 20;
    glob->menu.pos_start.y = 300;
    glob->menu.pos_setting.y = 400;
    glob->menu.pos_exit.y = 500;

    glob->menu.start = hover(glob, "assets/menu/play.jpg", "assets/menu/play_hover.jpg", 286, 98, glob->menu.pos_start);
    glob->menu.setting =
        hover(glob, "assets/menu/option.jpg", "assets/menu/option_hover.jpg", 286, 98, glob->menu.pos_setting);
    glob->menu.exit = hover(glob, "assets/menu/exit.jpg", "assets/menu/exit_hover.jpg", 286, 98, glob->menu.pos_exit);

    glob->menu.background = bunny_load_pixelarray("assets/menu/menu2.jpg");
}

int menu(t_glob *glob)
{
    static bool son;
    t_bunny_position pos_temp, pos_moon;
    t_bunny_music *easter_egg;

    if (son == false)
    {
        glob->music = bunny_load_music("assets/menu/menu.ogg");
        glob->music->sound.volume = glob->volume;
        bunny_sound_play(&glob->music->sound);
        son = true;
    }

    menu_view(glob);

    pos_moon.x = 642;
    pos_moon.y = 152;
    if (verif_click(glob->mouse, pos_moon, 50, 50) == true && glob->click == true)
    {
        easter_egg = bunny_load_music("assets/easter_egg.ogg");
        easter_egg->sound.volume = glob->volume;
        bunny_sound_play(&easter_egg->sound);
        bunny_usleep(1e6);
        bunny_delete_sound(&easter_egg->sound);
    }

    pos_temp = calcul_pos(glob->menu.pos_setting, 286, 98);
    if (verif_click(glob->mouse, pos_temp, 143, 49) == true && glob->click == true)
        return -1;

    pos_temp = calcul_pos(glob->menu.pos_exit, 286, 98);
    if (verif_click(glob->mouse, pos_temp, 143, 49) == true && glob->click == true)
        return -2;

    pos_temp = calcul_pos(glob->menu.pos_start, 286, 98);
    if (verif_click(glob->mouse, pos_temp, 143, 49) == true && glob->click == true)
        return 1;

    bunny_blit(&glob->screen.win->buffer, &glob->menu.background->clipable, NULL);
    bunny_blit(&glob->screen.win->buffer, &glob->menu.start->clipable, &glob->menu.pos_start);
    bunny_blit(&glob->screen.win->buffer, &glob->menu.setting->clipable, &glob->menu.pos_setting);
    bunny_blit(&glob->screen.win->buffer, &glob->menu.exit->clipable, &glob->menu.pos_exit);
    bunny_display(glob->screen.win);
    return 0;
}