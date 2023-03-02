/*
 * E89 Pedagogical & Technical Lab
 * project:     2022_runner
 * created on:  2023-01-23 - 10:29 +0100
 * 1st author:  quentin.gimenez - quentin.gimenez
 * description: fov
 */

#include "stu.h"
#include "display.h"

void fov(struct display *ds, unsigned int main_ray, unsigned int ray)
{
    t_bunny_position wall;
    t_accurate_pos hit;
    double angle;
    double coef;

    if (ds->player.fov <= 0) {
        return;
    }
    coef = ds->map.height;
    if (ds->map.height > ds->map.width) {
        coef = ds->map.width;
    }
    coef = 1.0 / ((ds->map.tile_size * coef) / ds->player.fov);
    angle = ds->player.angle - (ds->player.fov / 2);
    while (angle < ds->player.angle + (ds->player.fov / 2)) {
        hit    = send_ray(&ds->map, &ds->player.pos, deg_to_rads(angle));
        hit.x *= ds->map.tile_size;
        hit.y *= ds->map.tile_size;
        wall   = pos_from_accurate(&hit);
        stu_draw_line(ds->ds_px, &ds->player.pix , &wall, ray);
        angle   += coef;
    }
    hit    = send_ray(&ds->map, &ds->player.pos, deg_to_rads(ds->player.angle));
    hit.x *= ds->map.tile_size;
    hit.y *= ds->map.tile_size;
    wall   = pos_from_accurate(&hit);
    stu_draw_line(ds->ds_px, &ds->player.pix , &wall, main_ray);
}
