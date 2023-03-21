/*
 * E89 Pedagogical & Technical Lab
 * project:     runner
 * created on:  2023-03-20 - 11:22 +0100
 * 1st author:  user - user
 * description: rotate player
 */

#include "stu.h"

void rotate(const bool *keys, struct display *ds)
{
    if (keys[BKS_LEFT])
        ds->player.angle += 2;
    if (keys[BKS_RIGHT])
        ds->player.angle -= 2;
}
