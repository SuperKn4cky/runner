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
    double speed;
    double angle;
    int fov;
    int level;
    double jump_height;
    double vertical_speed;
    double gravity;
    bool is_jumping;
    bool pause;
};

#endif // PLAYER_H_
