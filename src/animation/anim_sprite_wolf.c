#include "animation.h"

static t_bunny_clipable *sprite_selector(int nbr, bool orientation)
{
    t_bunny_clipable *sprite;
    if (orientation == true)
    {
        if (nbr == 5)
            sprite = bunny_load_picture("assets/stage_4/werewolf_spritesheet.png");
        else if (nbr == 3)
            sprite = bunny_load_picture("assets/stage_4/werewolf_spritesheet.png");
        else if (nbr == 2)
            sprite = bunny_load_picture("assets/stage_4/werewolf_spritesheet.png");
        else
            sprite = bunny_load_picture("assets/stage_4/werewolf_spritesheet.png");
    }
    else
    {
        if (nbr == 5)
            sprite = bunny_load_picture("assets/stage_4/werewolf_spritesheet.png");
        else if (nbr == 3)
            sprite = bunny_load_picture("assets/stage_4/werewolf_spritesheet.png");
        else if (nbr == 2)
            sprite = bunny_load_picture("assets/stage_4/werewolf_spritesheet.png");
        else
            sprite = bunny_load_picture("assets/stage_4/werewolf_spritesheet.png");
    }
    return sprite;
}

void anim_walk_wolf(t_glob *glob, t_bunny_pixelarray *dest, t_bunny_position pos_screen, int size, int frame,
                    bool orientation)
{
    t_bunny_clipable *sprite;
    t_bunny_position pos[2];
    pos[0].x = pos_screen.x - 20;
    pos[0].y = pos_screen.y - 60;
    pos[1].x = 0;
    pos[1].y = 0;
    sprite = sprite_selector(size, orientation);
    sprite->clip_height = 320 / 4;
    sprite->clip_width = 320 / 4;
    frame = frame % 4;
    sprite->clip_x_position = frame * 80;
    if (orientation == false)
        sprite->clip_y_position = 160;
    else
        sprite->clip_y_position = 80;
    bunny_blit(&glob->screen.win->buffer, &dest->clipable, NULL);
    bunny_blit(&glob->screen.win->buffer, sprite, pos);
    bunny_display(glob->screen.win);
    bunny_delete_clipable(sprite);
}

void idle_anim_wolf(t_glob *glob, t_bunny_position pos_screen, int size)
{
    t_bunny_clipable *sprite;
    t_bunny_position ok[2];
    ok[0].x = pos_screen.x - 20;
    ok[0].y = pos_screen.y - 40;
    ok[1].x = 0;
    ok[1].y = 0;
    sprite = sprite_selector(size, true);
    sprite->clip_height = 320 / 4;
    sprite->clip_width = 320 / 4;
    bunny_blit(&glob->screen.win->buffer, sprite, ok);
    bunny_delete_clipable(sprite);
}

// idle_anim_wolf(glob, plan, glob->graph->array[glob->graph_nbr].head->pos, size);