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
    if (keys[BKS_SPACE] && !ds->player.is_jumping) {
        ds->player.is_jumping = true;
        ds->player.vertical_speed = 5.0;
    }
    if (ds->player.is_jumping) {
        ds->player.jump_height += ds->player.vertical_speed;
        ds->player.vertical_speed -= ds->player.gravity;

        if (ds->player.jump_height <= 0) {
            ds->player.jump_height = 0;
            ds->player.is_jumping = false;
            ds->player.vertical_speed = 0;
        }
    }
}
