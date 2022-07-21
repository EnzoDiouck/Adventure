#include "setting.h"

static t_setting setting_view(t_glob *glob)
{
  t_setting setting;

  setting.pos_volume.x = 250;
  setting.pos_volume.y = 200;
  setting.pos_up_arrow.x = setting.pos_down_arrow.x = 380;
  setting.pos_up_arrow.y = 210;
  setting.pos_down_arrow.y = 260;
  setting.pos_back_arrow.x = 0;
  setting.pos_back_arrow.y = 530;

  setting.up_arrow = hover(glob, "assets/setting/up_arrow.png", "assets/setting/up_arrow_hover.png", 30, 30, setting.pos_up_arrow);
  setting.down_arrow = hover(glob, "assets/setting/down_arrow.png", "assets/setting/down_arrow_hover.png", 30, 30, setting.pos_down_arrow);
  setting.back_arrow = hover(glob, "assets/back_arrow.png", "assets/back_arrow_hover.png", 150, 64, setting.pos_back_arrow);

  setting.background = bunny_load_pixelarray("assets/menu/menu.jpg");
  setting.volume = bunny_load_pixelarray("assets/setting/volume.png");
  return setting;
}

int setting(t_glob *glob)
{
  t_bunny_pixelarray *font;
  t_bunny_position pos_temp, pos_text_volume;
  t_setting setting;

  setting = setting_view(glob);
  font = bunny_load_pixelarray("assets/font.png");
  pos_text_volume.x = 420;
  pos_text_volume.y = 243;
  pos_temp = calcul_pos(setting.pos_back_arrow, 150, 64);
  if (verif_click(glob->mouse, pos_temp, 75, 32) == true && glob->click == true)
    return 0;

  pos_temp = calcul_pos(setting.pos_up_arrow, 30, 30);
  if (verif_click(glob->mouse, pos_temp, 15, 15) == true && glob->click == true)
    if(glob->volume <= 95)
      glob->volume += 5;

  pos_temp = calcul_pos(setting.pos_down_arrow, 30, 30);
  if (verif_click(glob->mouse, pos_temp, 15, 15) == true && glob->click == true)
    if (glob->volume >= 5)
      glob->volume -= 5;

  draw_back_text(setting.background, pos_text_volume, BLACK);
  std_text(setting.background, font, pos_text_volume, std_printbase10(glob->volume), WHITE);
  pos_text_volume.x += 30;
  std_letter(setting.background, font, pos_text_volume, '%', WHITE);
  
  bunny_blit(&glob->screen.win->buffer, &setting.background->clipable, NULL);
  bunny_blit(&glob->screen.win->buffer, &setting.volume->clipable, &setting.pos_volume);
  bunny_blit(&glob->screen.win->buffer, &setting.up_arrow->clipable, &setting.pos_up_arrow);
  bunny_blit(&glob->screen.win->buffer, &setting.down_arrow->clipable, &setting.pos_down_arrow);
  bunny_blit(&glob->screen.win->buffer, &setting.back_arrow->clipable, &setting.pos_back_arrow);
  bunny_display(glob->screen.win);
  glob->music->sound.volume = glob->volume;
  return -1;
}
  
