#include "play.h"

void game(t_glob *glob)
{
    static bool mus;

    if (mus == false)
    {
        mus = true;
        bunny_delete_sound(&glob->music->sound);
        glob->music = bunny_load_music("assets/main_theme.ogg");
        glob->music->sound.volume = glob->volume;
        bunny_sound_play(&glob->music->sound);
    }

    if (glob->stage_nbr == 0)
        stage_0(glob);
    else if (glob->stage_nbr == 1)
        stage_1(glob);
    else if (glob->stage_nbr == 2)
        stage_2(glob);
    else if (glob->stage_nbr == 3)
        stage_3(glob);
    else if (glob->stage_nbr == 4)
        stage_4(glob);
}
