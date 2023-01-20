/*
 * E89 Pedagogical & Technical Lab
 * project:     runner
 * created on:  2022-12-06 - 10:31 +0100
 * 1st author:  quentin.gimenez - quentin.gimenez
 * description: structure
 */

#include <lapin.h>

#ifndef MAP_H_
#define MAP_H_

struct map {
    t_bunny_accurate_position player;
    t_bunny_position pix;
    int tile_size;
    int width;
    int height;
    int *map;
    double angle;
};

#endif // MAP_H_
