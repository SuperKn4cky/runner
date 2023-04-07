/*
 * E89 Pedagogical & Technical Lab
 * project:     runner
 * created on:  2023-03-06 - 09:45 +0100
 * 1st author:  user - user
 * description: 3d
 */

#include <stu.h>

static void sky_ground(struct display *ds)
{
    int width;
    int height;
    int total;
    int i;
    unsigned int *pix;

    width = ds->ds_px->clipable.clip_width;
    height = ds->ds_px->clipable.clip_height;
    total = (width * height) - 1;
    i = (width * height) / 2;
    pix = (unsigned int *) ds->ds_px->pixels;
    while (total > i) {
        pix[total] = BLACK;
        total -= 1;
    }
    while (i >= 0) {
        pix[i] = BLUE;
        i -= 1;
    }
}

static void draw_wall(struct display *ds, int size_wall, int pos)
{
    unsigned int color;
    t_bunny_position pix;
    int width;
    int height;
    int i;

    i = 0;
    width = ds->ds_px->clipable.clip_width;
    height = ds->ds_px->clipable.clip_height;
    pix.x = width - pos;
    pix.y = height / 2;
    if (ds->map.type_wall == 2) {
        color = mk_colour(255, 0, 0, 1);
    } else if (ds->map.type_wall == 1 || ds->map.type_wall == 0) {
        color = mk_colour(255, 255, 255, 1);
    } else {
        color = mk_colour(255, 255, 0, 1);
    }
    while (i <= size_wall / 2) {
        put_pixel(ds->ds_px, &pix, color);
        pix.y += 1;
        i += 1;
    }
    i = 0;
    pix.y = height / 2;
    while (i <= size_wall / 2) {
        put_pixel(ds->ds_px, &pix, color);
        pix.y -= 1;
        i += 1;
    }
}

static void fov(struct display *ds)
{
    double angle;
    double coef;
    double size_wall;
    int i;

    i = 0;
    coef  = ds->player.fov / (double) ds->ds_px->clipable.clip_width;
    angle = ds->player.angle - (ds->player.fov / 2);
    ds->map.type_wall = 0;
    while (i < ds->ds_px->clipable.clip_width) {
        send_ray(&ds->map, &ds->player.pos, deg_to_rads(angle));
        size_wall = SIZE_WALL(ds, angle) * 0.75;
        if (size_wall > ds->ds_px->clipable.clip_height) {
            size_wall = ds->ds_px->clipable.clip_height;
        }
        draw_wall(ds, size_wall, i);
        angle += coef;
        i += 1;
    }
}

void raycasting(struct display *ds)
{
    if (ds->player.level == 0) {
        clear_pixelarray(ds->ds_px, BLACK);
        return;
    }
    sky_ground(ds);
    fov(ds);
}
