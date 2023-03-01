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
    int coef;

    end = move_forward(start, angle, 0.01);
    coef = map->height;
    if (map->height > map->width) {
        coef = map->width;
    }
    while (map->map[(int)end.x + coef * (int)end.y] == 0) {
        end = move_forward(&end, angle, 0.01);
    }
    return (end);
}
