/*
 * E89 Pedagogical & Technical Lab
 * project:     tp_laser
 * created on:  2023-01-16 - 10:52 +0100
 * 1st author:  quentin.gimenez - quentin.gimenez
 * description: pos from accurate
 */

#include "stu.h"

t_bunny_position pos_from_accurate(const t_accurate_pos *accurate)
{
    t_bunny_position pos;

    pos.x = accurate->x;
    pos.y = accurate->y;
    return (pos);
}
