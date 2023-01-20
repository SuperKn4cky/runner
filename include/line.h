/*
 * E89 Pedagogical & Technical Lab
 * project:     tp_laser
 * created on:  2023-01-19 - 10:24 +0100
 * 1st author:  quentin.gimenez - quentin.gimenez
 * description: struct draw line
 */

#ifndef LINE_H_
#define LINE_H_

struct line {
    int width_diff;
    int height_diff;
    float ratio;
    t_bunny_position position;
    t_bunny_position pos_a;
    t_bunny_position pos_b;
    t_bunny_position good_pos_a;
    t_bunny_position good_pos_b;
};

#endif // LINE_H_
