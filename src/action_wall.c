/*
 * E89 Pedagogical & Technical Lab
 * project:     runner
 * created on:  2023-04-05 - 12:17 +0200
 * 1st author:  user - user
 * description: action for each wall
 */

#include "stu.h"

void action_wall(struct display *ds)
{
    int angle;

    angle = 0;
    while (angle < 360) {
        if (POS_TO_MAP(ds->map.map,
                       ds->map.max_size,
                       move_forward(&ds->player.pos, angle, 0.1)) == 2) {
            ds->player.level += 1;
            reset_player_pos(ds);
        }
        angle += 1;
    }
}
