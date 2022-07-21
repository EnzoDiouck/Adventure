#include "animation.h"

char *next_frame(char *frame, int nbr)
{
    int i;

    i = 0;
    while (frame[i] > '9' || frame[i] < '0')
        i++;
    if (nbr < 9)
    {
        i++;
        frame[i] = nbr + '0';
    }
    else
    {
        frame[i] = (nbr / 10 % 10) + '0';
        frame[i + 1] = (nbr % 10) + '0';
    }
    return frame;
}

void animation(t_glob *glob, int nbr_frame, char *frame0, char *sound, int duration)
{
    int i;
    t_bunny_music *music;

    i = 0;
    music = bunny_load_music(sound);
    music->sound.volume = 100;
    bunny_sound_play(&music->sound);
    while (i != nbr_frame + 1)
    {
        std_clear_pixelarray(glob->screen.pic, BLACK);
        glob->screen.pic = bunny_load_pixelarray(frame0);
        i++;
        frame0 = next_frame(frame0, i);
        bunny_blit(&glob->screen.win->buffer, &glob->screen.pic->clipable, NULL);
        bunny_display(glob->screen.win);
        bunny_usleep(duration);
    }
    bunny_delete_sound(&music->sound);
}

void pegi_18(t_glob glob)
{
    t_bunny_music *music;

    music = bunny_load_music("assets/menu/18.ogg");
    music->sound.volume = glob.volume;
    bunny_sound_play(&music->sound);
    glob.screen.pic = bunny_load_pixelarray("assets/menu/-18.jpg");
    bunny_blit(&glob.screen.win->buffer, &glob.screen.pic->clipable, NULL);
    bunny_display(glob.screen.win);
    bunny_usleep(4e6);
    bunny_delete_sound(&music->sound);
}
