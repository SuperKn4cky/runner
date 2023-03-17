/*
 * E89 Pedagogical & Technical Lab
 * project:     2022_runner
 * created on:  2023-01-23 - 10:29 +0100
 * 1st author:  quentin.gimenez - quentin.gimenez
 * description: fov
 */

#include "stu.h"
#include "display.h"

static void sky_ground(struct display *ds)
{
    int width;
    int height;
    int total;
    int i;
    unsigned int *pix;

    width = ds->ds_px_3d->clipable.clip_width;
    height = ds->ds_px_3d->clipable.clip_height;
    total = width * height;
    i = total / 2;
    pix = (unsigned int *) ds->ds_px_3d->pixels;
    while (total > i) {
        pix[total] = BLACK;
        total -= 1;
    }
    while (i > 0) {
        pix[i] = BLUE;
        i -= 1;
    }
}

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
    coef  = ds->player.fov / ds->map.width;
    angle = ds->player.angle - (ds->player.fov / 2);
    sky_ground(ds);
    while (angle < ds->player.angle + (ds->player.fov / 2)) {
        hit    = send_ray(&ds->map, &ds->player.pos, deg_to_rads(angle));
        hit.x *= ds->map.tile_size;
        hit.y *= ds->map.tile_size;
        wall   = pos_from_accurate(&hit);
        stu_draw_line(ds->ds_px, &ds->player.pix , &wall, ray);
        trois_d(ds, angle, wall);
        angle += coef;
    }
    hit    = send_ray(&ds->map, &ds->player.pos, deg_to_rads(ds->player.angle));
    hit.x *= ds->map.tile_size;
    hit.y *= ds->map.tile_size;
    wall   = pos_from_accurate(&hit);
    stu_draw_line(ds->ds_px, &ds->player.pix , &wall, main_ray);
}
