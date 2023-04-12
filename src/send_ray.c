/*
 * E89 Pedagogical & Technical Lab
 * project:     tp_laser
 * created on:  2023-01-16 - 11:56 +0100
 * 1st author:  quentin.gimenez - quentin.gimenez
 * description: send ray
 */

#include "stu.h"

t_accurate_pos send_ray(struct map *map,
                        const t_accurate_pos *start,
                        double angle)
{
    t_accurate_pos end;
    double pas;

    pas = 0.005;
    map->distance = 0;
    end = move_forward(start, angle, pas);
    if (map->map == NULL) {
        map->distance = 0;
        end.x = 0;
        end.y = 0;
        return (end);
    }
    while (POS_TO_MAP(map->map, map->max_size, end) == 0) {
        end = move_forward(&end, angle, pas);
        map->distance += pas;
    }
    map->type_wall = POS_TO_MAP(map->map,
                                  map->max_size,
                                  move_forward(&end, angle, 0.01));
    return (end);
}
