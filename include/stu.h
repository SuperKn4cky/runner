/*
 * E89 Pedagogical & Technical Lab
 * project:     tp_laser
 * created on:  2022-11-22 - 09:38 +0100
 * 1st author:  quentin.gimenez - quentin.gimenez
 * description: lib
 */

#ifndef STU_H_
#define STU_H_

#include <math.h>
#include <lapin.h>
#include "display.h"
#include <stdio.h>

#define MAX_SIZE(A) (((A)->map.height) > ((A)->map.width)       \
                     ? ((A)->map.height) : ((A)->map.width))
#define POS_TO_MAP(MAP, SIZE, POS) (MAP[((int) POS.x)                   \
                                        + (SIZE) * ((int) POS.y)])
#define SIZE_WALL(C, ANGLE) (((C)->ds_px->clipable.clip_height) /      \
                               (((C)->map.distance)                     \
                                * (double) (cos(deg_to_rads(((C)->player.angle)) \
                                       - (deg_to_rads(ANGLE))))))
typedef t_bunny_accurate_position t_accurate_pos;
void clear_pixelarray(t_bunny_pixelarray *pxa, unsigned int color);
double deg_to_rads(double degrees);
t_accurate_pos move_forward(const t_accurate_pos *start,
                            double               angle,
                            double               len);
t_bunny_position pos_from_accurate(const t_accurate_pos *);
t_accurate_pos send_ray(struct map *map,
                        const t_accurate_pos *start,
                        double angle);
void draw_impact(struct map *map,
                 t_bunny_pixelarray *pxa,
                 const t_accurate_pos * start,
                 double angle);
void put_pixel(t_bunny_pixelarray *pxa,
               t_bunny_position *pos,
               unsigned int color);
void stu_draw_line(t_bunny_pixelarray *px,
                   t_bunny_position *pos_a,
                   t_bunny_position *pos_b,
                   unsigned int color);
float get_ratio(int a, int b, int x);
int get_value(int a, int b, float ratio);
void move(const bool *keys, struct display *ds);
void rotate(const bool *keys, struct display *ds);
void deux_d(struct display *ds);
void trois_d(struct display *ds);

#endif // STU_H_
