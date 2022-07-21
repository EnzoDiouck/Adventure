#include "loop_function.h"

t_bunny_response loop_key(t_bunny_event_state state, t_bunny_keysym keycode, void *d)
{
    t_glob *glob;
    glob = (t_glob *)d;
    (void)d;
    if (keycode == BKS_ESCAPE && state == GO_DOWN)
    {
        bunny_delete_sound(&glob->music->sound);
        return 0;
    }
    if (keycode == BKS_SPACE && state == GO_DOWN)
        glob->tuto++;
    return GO_ON;
}

t_bunny_response loop_move(const t_bunny_position *relative, void *d)
{
    (void)d;
    (void)relative;
    return GO_ON;
}

t_bunny_response loop_click(t_bunny_event_state state, t_bunny_mouse_button button, void *data)
{
    t_glob *glob;

    glob = (t_glob *)data;
    if (button == BMB_LEFT && state == GO_DOWN)
        glob->click = true;
    return GO_ON;
}

t_bunny_response loop_function(void *d)
{
    t_glob *glob;
    static int scene;

    glob = (t_glob *)d;
    glob->mouse = bunny_get_mouse_position();
    if (scene == 0)
        if ((scene = menu(glob)) == -2)
        {
            bunny_delete_sound(&glob->music->sound);
            return 0;
        }
    if (scene == -1)
        scene = setting(glob);
    if (scene == 1)
        game(glob);
    glob->click = false;
    return GO_ON;
}
