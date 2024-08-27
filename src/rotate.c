/*
 * E89 Pedagogical & Technical Lab
 * project:     runner
 * created on:  2023-03-20 - 11:22 +0100
 * 1st author:  user - user
 * description: rotate player
 */

#include <stdio.h>
#include "stu.h"

void rotate(const bool *keys, struct display *ds)
{
    t_bunny_position *mouse;
    double ratio;

    mouse = (t_bunny_position *) bunny_get_mouse_position();
    ratio = get_ratio(ds->ds_px->clipable.clip_width / 2,
                      ds->ds_px->clipable.clip_width,
                      mouse->x);
    ds->player.angle -= ratio * 20;
    bunny_set_mouse_position_window(ds->ds_win,
                                    ds->ds_px->clipable.clip_width /2,
                                    ds->ds_px->clipable.clip_height /2);
    if (keys[BKS_LEFT])
        ds->player.angle += 4;
    if (keys[BKS_RIGHT])
        ds->player.angle -= 4;
}
