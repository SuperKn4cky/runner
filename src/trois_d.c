/*
 * E89 Pedagogical & Technical Lab
 * project:     runner
 * created on:  2023-03-06 - 09:45 +0100
 * 1st author:  user - user
 * description: 3d
 */

#include <stu.h>

void trois_d(struct display *ds, double angle, t_bunny_position wall)
{
    t_bunny_position distance;

    distance.x = ds->player.pix.x - wall.x;
    distance.y = ds->player.pix.y - wall.y;
    if (distance.x < 0) {
        distance.x *= -1;
    }
    if (distance.y < 0) {
        distance.y *= -1;
    }
    printf("x: %d y: %d\n", distance.x, distance.y);
    (void) angle;
}
