#include "text.h"

unsigned int std_get_pixel(t_bunny_pixelarray *px, t_bunny_position pos)
{
    unsigned int *pixel;

    pixel = px->pixels;
    if (pos.x >= 0 && pos.x < px->clipable.buffer.width && pos.y >= 0 && pos.y < px->clipable.buffer.height)
        return (pixel[pos.y * px->clipable.buffer.width + pos.x]);
    else
        return BLACK;
}
