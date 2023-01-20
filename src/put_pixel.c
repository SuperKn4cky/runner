/*
 * E89 Pedagogical & Technical Lab
 * project:     tp_sphere
 * created on:  2023-01-12 - 09:49 +0100
 * 1st author:  quentin.gimenez - quentin.gimenez
 * description: put pixel
 */

#include <lapin.h>

void put_pixel(t_bunny_pixelarray *pxa,
               t_bunny_position *pos,
               unsigned int color)
{
    int width;
    int height;
    int position;
    unsigned int *tmp;

    width = pxa->clipable.clip_width;
    height = pxa->clipable.clip_height;
    tmp = (unsigned int *) pxa->pixels;
    position = (width * pos->y) + pos->x;
    if (pos->x < width && pos->y <= height
        && pos->x >= 0 && pos->y >= 0) {
        tmp[position] = color;
    }
}
