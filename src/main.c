#include "animation.h"
#include "loop_function.h"
#include "menu.h"
#include "struct.h"
#include <time.h>

int main()
{
    t_glob glob;

    glob.volume = 100;

    glob.screen.win = bunny_start(900, 600, false, "WereWolf");
    glob.screen.pic = bunny_new_pixelarray(glob.screen.win->buffer.width, glob.screen.win->buffer.height);
    glob.click = false;
    glob.game_button = 0;
    glob.stage_nbr = 0;
    glob.tuto = 0;
    glob.check_show = false;
    glob.taken = false;
    glob.graph_wolf_nbr = 7;
    glob.text = malloc(sizeof(char) * 100);
    glob.text = std_memset(glob.text, 0, 100);
    srand(time(NULL));
    pegi_18(glob);

    bunny_set_key_response(loop_key);
    bunny_set_click_response(loop_click);
    bunny_set_move_response(loop_move);
    bunny_set_loop_main_function(loop_function);
    bunny_loop(glob.screen.win, 60, &glob);
    return 0;
}
