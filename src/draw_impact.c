/*
 * E89 Pedagogical & Technical Lab
 * project:     tp_laser
 * created on:  2023-01-16 - 11:56 +0100
 * 1st author:  quentin.gimenez - quentin.gimenez
 * description: draw impact
 */

#include "stu.h"
#include "map.h"

void draw_impact(struct map *map,
                 t_bunny_pixelarray *pxa,
                 const t_accurate_pos *start,
                 double angle)
{
    t_bunny_position end;
    t_accurate_pos tmp;

    tmp = send_ray(map, start, angle);
    tmp.x *= map->tile_size;
    tmp.y *= map->tile_size;
    end = pos_from_accurate(&tmp);
    put_pixel(pxa, &end, WHITE);
}
