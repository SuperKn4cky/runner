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
    while (i > 0) {
        pix[i] = BLUE;
        i -= 1;
    }
}

static void draw_wall(struct display *ds, int size_wall, int pos)
{
    t_bunny_position pix;
    int i;

    i = 0;
    pix.x = (ds->map.width * ds->map.tile_size) - pos;
    pix.y = (ds->map.height * ds->map.tile_size) / 2;
    while (i < size_wall / 2) {
        put_pixel(ds->ds_px, &pix, WHITE);
        pix.y += 1;
        i += 1;
    }
    i = 0;
    pix.y = (ds->map.height* ds->map.tile_size) / 2;
    while (i < size_wall / 2) {
        put_pixel(ds->ds_px, &pix, WHITE);
        pix.y -= 1;
        i += 1;
    }
}

static void fov(struct display *ds)
{
    double angle;
    double coef;
    double c_is_monkey;
    int i;

    i = 0;
    c_is_monkey = (ds->map.width * ds->map.tile_size);
    coef  = ds->player.fov / c_is_monkey;
    angle = ds->player.angle - (ds->player.fov / 2);
    while (i < (ds->map.width * ds->map.tile_size)) {
        send_ray(&ds->map, &ds->player.pos, deg_to_rads(angle));
        draw_wall(ds, SIZE_WALL(ds, angle), i);
        angle += coef;
        i += 1;
    }
}

void trois_d(struct display *ds)
{
    sky_ground(ds);
    fov(ds);
    (void) ds;
}
