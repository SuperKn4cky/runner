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
    unsigned int *pix;
    t_accurate_pos end;

    width  = ds->ds_px->clipable.clip_width;
    height = ds->ds_px->clipable.clip_height;
    pix    = (unsigned int *) ds->ds_px->pixels;
    end.y = height;
    while (end.y > 0) {
        end.x = width;
        while (end.x > 0) {
            if (ds->map.map[(((int)end.y / 100) * ds->map.width) + ((int)end.x / 100)] == 1) {
                pix[(int)end.x * (int)end.y] = color;
            } else {
                pix[(int)end.x * (int)end.y] = BLACK;
            }
            end.x -= 1;
        }
        end.y -= 1;
    }
}

