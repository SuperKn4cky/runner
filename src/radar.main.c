/*
 * E89 Pedagogical & Technical Lab
 * project:     tp_laser
 * created on:  2023-01-19 - 09:48 +0100
 * 1st author:  quentin.gimenez - quentin.gimenez
 * description: main
 */

#include <assert.h>
#include <lapin.h>
#include <math.h>
#include "map.h"
#include "stu.h"

int main(void)
{
    t_bunny_window           *win;
    t_bunny_pixelarray       *px;
    t_bunny_accurate_position pos;
    double                    angle;
    t_accurate_pos            hit;
    t_bunny_position          pos_a;
    t_bunny_position          pos_b;

    int mx[6 * 6] = {
        1, 1, 1, 1, 1, 1,
            1, 0, 0, 0, 0, 1,
            1, 0, 0, 0, 0, 1,
            1, 0, 0, 0, 1, 1,
            1, 1, 0, 1, 1, 1,
            1, 1, 1, 1, 1, 1,
            };
    struct map map;
    map.width     = 6;
    map.height    = 6;
    map.tile_size = 100;
    map.map       = &mx[0];
    pos.x         = 2.5;
    pos.y         = 2.5;
    angle         = 0;
    win           = bunny_start(map.width * map.tile_size,
                                map.height * map.tile_size,
                                false,
                                "fl: TP Laser");
    px            = bunny_new_pixelarray(win->buffer.width, win->buffer.height);
    pos_a         = pos_from_accurate(&pos);
    pos_a.x      *= map.tile_size;
    pos_a.y      *= map.tile_size;
    while (true) {
        clear_pixelarray(px, BLACK);
        hit       = send_ray(&map, &pos, angle);
        hit.x    *= map.tile_size;
        hit.y    *= map.tile_size;
        pos_b     = pos_from_accurate(&hit);
        stu_draw_line(px, &pos_a, &pos_b, GREEN);
        draw_impact(&map, px, &pos, angle);
        angle    -= 0.0045;
        bunny_blit(&win->buffer, &px->clipable, NULL);
        bunny_display(win);
    }
    bunny_usleep(5e6);
    bunny_delete_clipable(&px->clipable);
    bunny_stop(win);
    return (0);
}
