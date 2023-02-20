/*
 * E89 Pedagogical & Technical Lab
 * project:     runner
 * created on:  2023-02-20 - 09:54 +0100
 * 1st author:  quentin.gimenez - quentin.gimenez
 * description: map
 */

#include "stu.h"

void map(struct display *ds, unsigned int height, unsigned int width)
{
    int mx[height * width] = {
        1, 1, 1, 1, 1, 1, 1, 1,
        1, 0, 0, 0, 0, 0, 0, 1,
        1, 0, 0, 0, 0, 0, 0, 1,
        1, 0, 0, 0, 1, 1, 0, 1,
        1, 1, 0, 1, 0, 0, 0, 1,
        1, 1, 0, 1, 0, 1, 0, 1,
        0, 0, 0, 0, 0, 0, 0, 1,
        1, 1, 1, 1, 1, 1, 1, 1,
    };
    ds->map.map = &mx[0];
}
