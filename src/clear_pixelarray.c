/*
 * E89 Pedagogical & Technical Lab
 * project:     tp_laser
 * created on:  2023-01-12 - 09:47 +0100
 * 1st author:  quentin.gimenez - quentin.gimenez
 * description: clear pixelarray
 */

#include <lapin.h>

void clear_pixelarray(t_bunny_pixelarray *pxa, unsigned int color)
{
    int width;
    int height;
    int total;
    unsigned int *pix;

    width = pxa->clipable.clip_width;
    height = pxa->clipable.clip_height;
    total = width * height;
    pix = (unsigned int *) pxa -> pixels;
    while (total > 0) {
        pix[total] = color;
        total -= 1;
    }
}
