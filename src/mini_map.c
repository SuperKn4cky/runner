/*
 * E89 Pedagogical & Technical Lab
 * project:     2022_runner
 * created on:  2023-01-23 - 10:29 +0100
 * 1st author:  quentin.gimenez - quentin.gimenez
 * description: fov
 */

#include "stu.h"

static t_bunny_position reduce(t_bunny_position pos)
{
    t_bunny_position pos_b;

    pos_b.x = pos.x / 5;
    pos_b.y = pos.y / 5;
    return (pos_b);
}

static t_accurate_pos *increase(struct display *ds, t_accurate_pos *pos)
{
    pos->x *= (ds->map.tile_size / 5);
    pos->y *= (ds->map.tile_size / 5);
    return (pos);
}

static void fov(struct display *ds)
{
    t_bunny_position player;
    t_bunny_position wall;
    t_accurate_pos hit;

    hit   = send_ray(&ds->map,
                     &ds->player.pos,
                     deg_to_rads(ds->player.angle - (ds->player.fov / 2)));
    wall   = pos_from_accurate(increase(ds, &hit));
    player = reduce(ds->player.pix);
    stu_draw_line(ds->ds_px, &player , &wall, GREEN);
    hit    = send_ray(&ds->map,
                      &ds->player.pos,
                      deg_to_rads(ds->player.angle + (ds->player.fov / 2)));
    wall   = pos_from_accurate(increase(ds, &hit));
    player = reduce(ds->player.pix);
    stu_draw_line(ds->ds_px, &player , &wall, GREEN);
    hit    = send_ray(&ds->map, &ds->player.pos, deg_to_rads(ds->player.angle));
    wall   = pos_from_accurate(increase(ds, &hit));
    player = reduce(ds->player.pix);
    stu_draw_line(ds->ds_px, &player , &wall, RED);
}

static void fill_wall(struct display *ds)
{
    int width;
    int height;
    t_bunny_position pos;
    t_bunny_position pix;

    width  = ds->map.width;
    height = ds->map.height;
    pos.y = height;
    while (pos.y > 0) {
        pos.x = width;
        while (pos.x > 0) {
            if (POS_TO_MAP(ds->map.map, ds->map.max_size, pos) == 1) {
                pix = pos;
                /*
                 * pix.x *= (ds->map.tile_size / 5);
                 * pix.y *= (ds->map.tile_size / 5);
                 */
                put_pixel(ds->ds_px, &pix, WHITE);
            }
            pos.x -= 0.01;
        }
        pos.y -= 0.01;
    }
}

void mini_map(struct display *ds)
{
    //clear_pixelarray(ds->ds_px, BLACK);
    fill_wall(ds);
    fov(ds);
}
