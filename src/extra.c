/*
 * E89 Pedagogical & Technical Lab
 * project:     runner
 * created on:  2023-04-05 - 11:39 +0200
 * 1st author:  user - user
 * description: extra keys actions
 */

#include "stu.h"

void extra(const bool *keys, struct display *ds)
{
    ds->player.speed = 0.05;
    if (keys[BKS_LSHIFT]) {
        ds->player.speed *= 2;
    }
}
