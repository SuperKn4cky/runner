/*
 * E89 Pedagogical & Technical Lab
 * project:     2022_runner
 * created on:  2023-01-23 - 10:29 +0100
 * 1st author:  quentin.gimenez - quentin.gimenez
 * description: fov
 */

#include "stu.h"
#include "display.h"

/*
 * static void fill_wall(struct display *ds)
 * {
 *     int width;
 *     int height;
 *     t_accurate_pos end;
 *     t_bunny_position pos;
 * 
 *     width  = ds->ds_px->clipable.clip_width;
 *     height = ds->ds_px->clipable.clip_height;
 *     end.y = height;
 *     while (end.y > 0) {
 *         end.x = width - 1;
 *         while (end.x > 0) {
 *             pos = pos_from_accurate(&end);
 *             if (POS_TO_MAP(ds->map.map, ds->map.max_size, end) == 1) {
 *                 put_pixel(ds->ds_px, &pos, WHITE);
 *             }
 *             end.x -= 1;
 *         }
 *         end.y -= 1;
 *     }
 * }
 */

static t_accurate_pos *reduce(struct display *ds, t_accurate_pos pos)
{
    pos.x *= ds->map.tile_size / 5;
    pos.y *= ds->map.tile_size / 5;
    return (pos);
}

static void fov(struct display *ds)
{
    t_bunny_position wall;
    t_accurate_pos hit;

    hit    = send_ray(&ds->map,
                      &ds->player.pos,
                      deg_to_rads(ds->player.angle - (ds->player.fov / 2)));
    wall   = pos_from_accurate(reduce(ds, hit));
    stu_draw_line(ds->ds_px, &ds->player.pix , &wall, GREEN);

    hit    = send_ray(&ds->map,
                      &ds->player.pos,
                      deg_to_rads(ds->player.angle + (ds->player.fov / 2)));
    wall   = pos_from_accurate(reduce(ds, hit));
    stu_draw_line(ds->ds_px, &ds->player.pix , &wall, GREEN);

    hit    = send_ray(&ds->map, &ds->player.pos, deg_to_rads(ds->player.angle));
    wall   = pos_from_accurate(reduce(ds, hit));
    stu_draw_line(ds->ds_px, &ds->player.pix , &wall, RED);
}

void deux_d(struct display *ds)
{
    //clear_pixelarray(ds->ds_px, BLACK);
    //fill_wall(ds);
    fov(ds);
}
