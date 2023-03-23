/*
 * E89 Pedagogical & Technical Lab
 * project:     tp_laser
 * created on:  2023-01-16 - 11:56 +0100
 * 1st author:  quentin.gimenez - quentin.gimenez
 * description: send ray
 */

#include "stu.h"
#include "map.h"

t_accurate_pos send_ray(struct map *map,
                        const t_accurate_pos *start,
                        double angle)
{
    t_accurate_pos end;
    double pas;

    pas = 0.01;
    end = move_forward(start, angle, pas);
    while (POS_TO_MAP(map->map, map->max_size, end) == 0) {
        end = move_forward(start, angle, pas);
        pas += 0.01;
    }
    map->distance = pas;
    return (end);
}
