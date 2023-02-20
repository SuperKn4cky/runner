/*
 * E89 Pedagogical & Technical Lab
 * project:     tp_laser
 * created on:  2022-11-22 - 09:38 +0100
 * 1st author:  quentin.gimenez - quentin.gimenez
 * description: lib
 */

#include <lapin.h>
#include "display.h"

#ifndef STU_H_
#define STU_H_

typedef t_bunny_accurate_position t_accurate_pos;
void map(struct display *ds, unsigned int height, unsigned int width);
void clear_pixelarray(t_bunny_pixelarray *pxa, unsigned int color);
double deg_to_rads(int degrees);
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
void fov(struct display *ds, unsigned int main_ray, unsigned int ray);
void fill_wall(struct display *ds, unsigned int color);
void move(t_bunny_keysym keycode, struct display *ds);

#endif // STU_H_
