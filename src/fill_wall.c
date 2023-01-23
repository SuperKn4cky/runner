/*
 * E89 Pedagogical & Technical Lab
 * project:     2022_runner
 * created on:  2023-01-23 - 11:48 +0100
 * 1st author:  quentin.gimenez - quentin.gimenez
 * description: fill_wall
 */

#include "stu.h"
#include "display.h"

#include <stdio.h>

void fill_wall(struct display *ds, unsigned int color)
{
    int width;
    int height;
    int total;
    unsigned int *pix;
    t_accurate_pos end;
    int coef;

    width = ds->ds_px->clipable.clip_width;
    height = ds->ds_px->clipable.clip_height;
    total = width * height;
    pix = (unsigned int *) ds->ds_px->pixels;
    coef = ds->map.height;
    if (ds->map.height < ds->map.width) {
        coef = ds->map.width;
    }
    while (total > 0) {
        end.x = (total / 100) / ds->map.height;
        end.y = (total / 100) / ds->map.width;
        //printf("x: %f | y: %f\n", end.x, end.y);
        if (ds->map.map[(int)end.x + coef * (int)end.y] == 0) {
            pix[total] = color;
            total -= 1;
        }
        total -= 1;
    }
}

