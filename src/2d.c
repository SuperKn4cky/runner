/*
 * E89 Pedagogical & Technical Lab
 * project:     2022_runner
 * created on:  2023-01-23 - 10:29 +0100
 * 1st author:  quentin.gimenez - quentin.gimenez
 * description: fov
 */

#include "stu.h"
#include "display.h"

static void fill_wall(struct display *ds)
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
            if (ds->map.map[(((int)end.y / ds->map.tile_size) * ds->map.width) +
                            ((int)end.x / ds->map.tile_size)] == 1) {
                put_pixel(ds->ds_px, &pos, WHITE);
            }
            end.x -= 1;
        }
        end.y -= 1;
    }
}

static void fov(struct display *ds)
{
    t_bunny_position wall;
    t_accurate_pos hit;
    double angle;
    double coef;
    double c_is_monkey;

    c_is_monkey = ds->map.width * ds->map.tile_size;
    coef  = ds->player.fov / c_is_monkey;
    angle = ds->player.angle - (ds->player.fov / 2);
    while (angle < ds->player.angle + (ds->player.fov / 2)) {
        hit    = send_ray(&ds->map, &ds->player.pos, deg_to_rads(angle));
        hit.x *= ds->map.tile_size;
        hit.y *= ds->map.tile_size;
        wall   = pos_from_accurate(&hit);
        stu_draw_line(ds->ds_px, &ds->player.pix , &wall, GREEN);
        angle += coef;
    }
    hit    = send_ray(&ds->map, &ds->player.pos, deg_to_rads(ds->player.angle));
    hit.x *= ds->map.tile_size;
    hit.y *= ds->map.tile_size;
    wall   = pos_from_accurate(&hit);
    stu_draw_line(ds->ds_px, &ds->player.pix , &wall, RED);
}

void deux_d(struct display *ds)
{
    clear_pixelarray(ds->ds_px, BLACK);
    fill_wall(ds);
    fov(ds);
}
