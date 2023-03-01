/*
 * E89 Pedagogical & Technical Lab
 * project:     2022_runner
 * created on:  2023-01-26 - 17:21 +0100
 * 1st author:  quentin.gimenez - quentin.gimenez
 * description: move player
 */

#include "stu.h"

static int good_coef(struct display *ds)
{
    int coef;

    coef = ds->map.height;
    if (ds->map.height > ds->map.width) {
        coef = ds->map.width;
    }
    return (coef);
}

static void stop(struct display *ds, int coef, int angle)
{
    if (ds->map.map[(int)ds->player.pos.x +
                    coef * (int)ds->player.pos.y] != 0
        || ds->player.pos.x < 0
        || ds->player.pos.y < 0) {
        ds->player.pos = move_forward(&ds->player.pos,
                                      deg_to_rads(ds->player.angle + angle),
                                      0.05);
    }
}

void move(t_bunny_keysym keycode, struct display *ds)
{
    int coef;

    coef = good_coef(ds);
    if (keycode == BKS_Z) {
        ds->player.pos = move_forward(&ds->player.pos,
                                      deg_to_rads(ds->player.angle),
                                      0.05);
        stop(ds, coef, 180);
    } else if (keycode == BKS_S) {
        ds->player.pos = move_forward(&ds->player.pos,
                                      deg_to_rads(ds->player.angle + 180),
                                      0.05);
        stop(ds, coef, 0);
    } else if (keycode == BKS_Q) {
        ds->player.pos = move_forward(&ds->player.pos,
                                      deg_to_rads(ds->player.angle + 90),
                                      0.05);
        stop(ds, coef, 270);
    } else if (keycode == BKS_D) {
        ds->player.pos = move_forward(&ds->player.pos,
                                      deg_to_rads(ds->player.angle - 90),
                                      0.05);
        stop(ds, coef, 90);
    }
}
