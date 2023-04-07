/*
 * E89 Pedagogical & Technical Lab
 * project:     runner
 * created on:  2023-04-05 - 13:06 +0200
 * 1st author:  user - user
 * description: reset player position to 1.5 1.5
 */

#include "stu.h"

void reset_player_pos(struct display *ds)
{
    ds->player.pos.x = 1.5;
    ds->player.pos.y = 1.5;
    ds->player.angle = 0;;
}
