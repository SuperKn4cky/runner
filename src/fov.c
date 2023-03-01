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
    double tmp;
    double angle;
    int coef;

    coef = ds->map.height;
    if (ds->map.height > ds->map.width) {
        coef = ds->map.width;
    }
    angle = 1.0 / ((ds->map.tile_size * coef) / ds->player.fov);
    printf("%f\n", angle);
    if (ds->player.fov <= 0) {
        return;
    }
    tmp = ds->player.angle - (ds->player.fov / 2);
    while (tmp < ds->player.angle + (ds->player.fov / 2)) {
        hit    = send_ray(&ds->map, &ds->player.pos, deg_to_rads(tmp));
        hit.x *= ds->map.tile_size;
        hit.y *= ds->map.tile_size;
        wall   = pos_from_accurate(&hit);
        stu_draw_line(ds->ds_px, &ds->player.pix , &wall, ray);
        tmp   += angle;
    }
    hit    = send_ray(&ds->map, &ds->player.pos, deg_to_rads(ds->player.angle));
    hit.x *= ds->map.tile_size;
    hit.y *= ds->map.tile_size;
    wall   = pos_from_accurate(&hit);
    stu_draw_line(ds->ds_px, &ds->player.pix , &wall, main_ray);
    put_pixel(ds->ds_px, &ds->player.pix, RED);
}
