/*
 * E89 Pedagogical & Technical Lab
 * project:     2022_runner
 * created on:  2023-01-26 - 17:21 +0100
 * 1st author:  quentin.gimenez - quentin.gimenez
 * description: move player
 */

#include "stu.h"

static void stop(struct display *ds, int angle)
{
    if (ds->map.map == NULL) {
        return;
    }
    if (POS_TO_MAP(ds->map.map, ds->map.max_size, ds->player.pos) != 0
        || ds->player.pos.x < 0
        || ds->player.pos.y < 0) {
        ds->player.pos = move_forward(&ds->player.pos,
                                      deg_to_rads(ds->player.angle + angle),
                                      ds->player.speed);
    }
}

void move(const bool *keys, struct display *ds)
{
    if (keys[BKS_Z]) {
        ds->player.pos = move_forward(&ds->player.pos,
                                      deg_to_rads(ds->player.angle),
                                      ds->player.speed);
        stop(ds, 180);
    }
    if (keys[BKS_S]) {
        ds->player.pos = move_forward(&ds->player.pos,
                                      deg_to_rads(ds->player.angle + 180),
                                      ds->player.speed);
        stop(ds, 0);
    }
    if (keys[BKS_Q]) {
        ds->player.pos = move_forward(&ds->player.pos,
                                      deg_to_rads(ds->player.angle + 90),
                                      ds->player.speed);
        stop(ds, 270);
    }
    if (keys[BKS_D]) {
        ds->player.pos = move_forward(&ds->player.pos,
                                      deg_to_rads(ds->player.angle - 90),
                                      ds->player.speed);
        stop(ds, 90);
    }
}

void rotate(const bool *keys, struct display *ds)
{
    t_bunny_position *mouse;
    double ratio;

    mouse = (t_bunny_position *) bunny_get_mouse_position();
    ratio = get_ratio(ds->ds_px->clipable.clip_width / 2,
                      ds->ds_px->clipable.clip_width,
                      mouse->x);
    bunny_set_mouse_position_window(ds->ds_win,
                                    ds->ds_px->clipable.clip_width /2,
                                    ds->ds_px->clipable.clip_height /2);
    ds->player.angle += ratio * 20;
    if (keys[BKS_LEFT])
        ds->player.angle += 4;
    if (keys[BKS_RIGHT])
        ds->player.angle -= 4;
}

void extra(const bool *keys, struct display *ds)
{
    ds->player.speed = 0.05;
    if (keys[BKS_LSHIFT]) {
        ds->player.speed *= 2;
    }
}
