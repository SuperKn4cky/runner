/*
 * E89 Pedagogical & Technical Lab
 * project:     2022_runner
 * created on:  2023-01-23 - 11:48 +0100
 * 1st author:  quentin.gimenez - quentin.gimenez
 * description: fill_wall
 */

#include "stu.h"
#include "display.h"

void fill_wall(struct display *ds, unsigned int color)
{
    int width;
    int height;
    t_accurate_pos end;
    t_bunny_position pos;

    width  = ds->ds_px->clipable.clip_width;
    height = ds->ds_px->clipable.clip_height;
    end.y = height;
    while (end.y >= 0) {
        end.x = width;
        while (end.x >= 0) {
            pos = pos_from_accurate(&end);
            if (ds->map.map[(((int)end.y / 100) * ds->map.width) +
                            ((int)end.x / 100)] == 1) {
                put_pixel(ds->ds_px, &pos, color);
            }
            end.x -= 1;
        }
        end.y -= 1;
    }
}

