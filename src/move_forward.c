/*
 * E89 Pedagogical & Technical Lab
 * project:     tp_laser
 * created on:  2023-01-16 - 10:52 +0100
 * 1st author:  quentin.gimenez - quentin.gimenez
 * description: move forward
 */

#include <lapin.h>
#include "stu.h"

typedef t_bunny_accurate_position t_accurate_pos;

t_accurate_pos move_forward(const t_accurate_pos *start,
                            double               angle,
                            double               len)
{
    t_accurate_pos end;

    end.x = (cos(angle) * len) + start->x;
    end.y = ((sin(angle) * len) * - 1) + start->y;
    return (end);
}
