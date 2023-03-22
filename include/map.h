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
    double distance;
    int tile_size;
    int max_size;
    int width;
    int height;
    int *map;
};

#endif // MAP_H_
