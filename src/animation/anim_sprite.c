#include "animation.h"

// pour la size du perso j'ai plusieur taille et je dois multiplier width, height, pos.x, pos.y par x/6 comme ca j'ai la
// bonne taille de perso

static void copy(t_bunny_pixelarray *dest, t_bunny_pixelarray *src)
{
    t_bunny_position pos;

    pos.x = 0;
    pos.y = 0;

    while (pos.x * pos.y < src->clipable.buffer.width * src->clipable.buffer.height)
    {
        if (pos.x == src->clipable.buffer.width)
        {
            pos.x = 0;
            pos.y++;
        }
        std_set_pixel(dest, pos, std_get_pixel(src, pos));
        pos.x++;
    }
}

static t_bunny_pixelarray *sprite_selector(int nbr, bool orientation)
{
    t_bunny_pixelarray *sprite;
    if (orientation == true)
    {
        if (nbr == 5)
            sprite = bunny_load_pixelarray("assets/game/sprite_man2.png");
        else if (nbr == 3)
            sprite = bunny_load_pixelarray("assets/game/sprite_man4.png");
        else if (nbr == 2)
            sprite = bunny_load_pixelarray("assets/game/sprite_man5.png");
        else
            sprite = bunny_load_pixelarray("assets/game/sprite_man2.png");
    }
    else
    {
        if (nbr == 5)
            sprite = bunny_load_pixelarray("assets/game/2sprite_man2.png");
        else if (nbr == 3)
            sprite = bunny_load_pixelarray("assets/game/2sprite_man4.png");
        else if (nbr == 2)
            sprite = bunny_load_pixelarray("assets/game/2sprite_man5.png");
        else
            sprite = bunny_load_pixelarray("assets/game/2sprite_man2.png");
    }
    return sprite;
}

void anim_walk(t_glob *glob, t_bunny_pixelarray *dest, t_bunny_position pos_screen, int size, int frame, bool orientation, bool check_poto)
{
    t_bunny_pixelarray *sprite, *old_dest;
    t_bunny_position pos;
    t_bunny_position old_pos, old_screen, temp_pos;
    int color, width, height;
    t_bunny_clipable *poto;

    poto = bunny_load_picture("assets/stage_3/poto.png");
    old_dest = bunny_new_pixelarray(dest->clipable.buffer.width, dest->clipable.buffer.height);
    sprite = sprite_selector(size, orientation);
    width = 107 * size / 6;
    height = 183 * size / 6;
    pos_screen.y = pos_screen.y - 183 * size / 6;
    old_screen.x = pos_screen.x;
    old_screen.y = pos_screen.y;
    copy(old_dest, dest);
    temp_pos.x = temp_pos.y = 0;
    pos.x = 78 * size / 6 + (width * (frame - 1));
    pos.y = 223 * size / 6;
    old_pos.x = pos.x;
    while (temp_pos.x * temp_pos.y < width * height)
    {
        if (temp_pos.x == width)
        {
            pos.x = old_pos.x;
            pos_screen.x = old_screen.x;
            pos.y++;
            pos_screen.y++;
            temp_pos.x = 0;
            temp_pos.y++;
        }
        color = std_get_pixel(sprite, pos);
        if (color != -2154277)
            std_set_pixel(dest, pos_screen, color);
        pos.x++;
        temp_pos.x++;
        pos_screen.x++;
    }
    bunny_blit(&glob->screen.win->buffer, &dest->clipable, NULL);
    if (check_poto == true)
        bunny_blit(&glob->screen.win->buffer, poto, NULL);
    bunny_display(glob->screen.win);
    // bunny_usleep(1e5); // slow tout le programm mais je veux pas
    pos_screen = old_screen;
    copy(dest, old_dest);
    frame++;
    bunny_delete_clipable(old_dest);
    bunny_delete_clipable(sprite);
}

void idle_anim(t_glob *glob, t_bunny_pixelarray *dest, t_bunny_position pos_screen, int size)
{
    t_bunny_pixelarray *sprite;
    t_bunny_position pos;
    t_bunny_position old_pos, old_screen, temp_pos;
    int color, width, height;

    sprite = sprite_selector(size, true);
    width = 107 * size / 6;
    height = 183 * size / 6;
    old_screen.x = pos_screen.x;
    old_screen.y = pos_screen.y;
    temp_pos.x = temp_pos.y = 0;
    pos.x = 108 * size / 6;
    pos.y = 22 * size / 6;
    old_pos.x = pos.x;
    while (temp_pos.x * temp_pos.y < width * height)
    {
        if (temp_pos.x == width)
        {
            pos.x = old_pos.x;
            pos.y++;
            pos_screen.x = old_screen.x;
            pos_screen.y++;
            temp_pos.x = 0;
            temp_pos.y++;
        }
        color = std_get_pixel(sprite, pos);
        if (color != -2154277)
            std_set_pixel(dest, pos_screen, color);
        temp_pos.x++;
        pos_screen.x++;
        pos.x++;
    }
    bunny_blit(&glob->screen.win->buffer, &dest->clipable, NULL);
    (void)glob;
    bunny_delete_clipable(sprite);
}