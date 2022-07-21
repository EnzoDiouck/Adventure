#include "set_pixel.h"

void std_set_line(t_bunny_pixelarray *px,
                  t_bunny_position *pos,
                  unsigned int color)
{
    double m;
    t_bunny_position test;
    t_bunny_position depart;

    m = 0;
    test.x = pos[1].x - pos[0].x;
    test.y = pos[1].y - pos[0].y;
    depart.x = pos[0].x;
    depart.y = pos[0].y;
    while (m < 1)
    {
        depart.x = pos[0].x + test.x * m;
        depart.y = pos[0].y + test.y * m;
        std_set_pixel(px, depart, color);
        m += 1.0 / sqrt(pow((pos[1].x - pos[0].x), 2) + pow((pos[1].y - pos[0].y), 2) + 5);
    }
}