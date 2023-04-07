/*
 * E89 Pedagogical & Technical Lab
 * project:     2022_runner
 * created on:  2023-01-23 - 09:40 +0100
 * 1st author:  quentin.gimenez - quentin.gimenez
 * description: player
 */

#include <lapin.h>

#ifndef PLAYER_H_
#define PLAYER_H_

struct player {
    t_bunny_accurate_position pos;
    t_bunny_position pix;
    double speed;
    double angle;
    int fov;
    int level;
};

#endif // PLAYER_H_
