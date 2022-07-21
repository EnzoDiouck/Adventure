#ifndef __CLEAR_PIXELARRAY_H__
#define __CLEAR_PIXELARRAY_H__

#include <lapin.h>

void std_set_pixel(t_bunny_pixelarray *px,
                   t_bunny_position   pos,
                   unsigned int       color);

void std_clear_pixelarray(t_bunny_pixelarray *picture, unsigned int color);

#endif /* __CLEAR_PIXELARRAY_H__ */
