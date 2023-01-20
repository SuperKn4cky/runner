/*
 * E89 Pedagogical & Technical Lab
 * project:     learning liblapin
 * created on:  2022-09-29 - 14:39 +0200
 * 1st author:  Élise C. Philippe - eriizu
 * description: events on a window
 */

#include <lapin.h>
#include "display.h"
#include "stu.h"

void refresh(struct display *ds)
{
    bunny_blit(&ds->ds_win->buffer, &ds->ds_px->clipable, NULL);
    bunny_display(ds->ds_win);
}

t_bunny_response key_event(t_bunny_event_state state,
                           t_bunny_keysym keycode,
                           void *data)
{
    t_bunny_accurate_position hit;
    t_bunny_position wall;
    struct display *ds;

    ds = data;
    if (state == GO_UP)
        return (GO_ON);
    if (keycode == BKS_ESCAPE)
        return (EXIT_ON_SUCCESS);
    else if (keycode == BKS_Z)
        ds->map.player.y -= 1;
    else if (keycode == BKS_S)
        ds->map.player.y += 1;
    else if (keycode == BKS_Q)
        ds->map.player.x -= 1;
    else if (keycode == BKS_D)
        ds->map.player.x += 1;
    clear_pixelarray(ds->ds_px, BLACK);
    ds->map.pix = pos_from_accurate(&ds->map.player);
    put_pixel(ds->ds_px, &ds->map.pix, WHITE);
    hit    = send_ray(&ds->map, &ds->map.player, ds->map.angle);
    hit.x *= ds->map.tile_size;
    hit.y *= ds->map.tile_size;
    wall  = pos_from_accurate(&hit);
    stu_draw_line(ds->ds_px, &ds->map.pix , &wall, GREEN);
    refresh(ds);
    return (GO_ON);
}

int main(void)
{
    int mx[6 * 6] = {
        1, 1, 1, 1, 1, 1,
        1, 0, 0, 0, 0, 1,
        1, 0, 0, 0, 0, 1,
        1, 0, 0, 0, 1, 1,
        1, 1, 0, 1, 1, 1,
        1, 1, 1, 1, 1, 1,
    };
    struct display display;
    struct map map;

    map.width            = 6;
    map.height           = 6;
    map.tile_size        = 100;
    map.map              = &mx[0];
    display.map.player.x = 2.5;
    display.map.player.y = 2.5;
    display.map.angle = 0;
    display.ds_win = bunny_start(map.width * map.tile_size,
                                 map.height * map.tile_size,
                                 false,
                                 "fl: tp event");
    display.ds_px = bunny_new_pixelarray(display.ds_win->buffer.width,
                                         display.ds_win->buffer.height);
    clear_pixelarray(display.ds_px, BLACK);
    display.map.pix    = pos_from_accurate(&display.map.player);
    display.map.pix.x *= map.tile_size;
    display.map.pix.y *= map.tile_size;
    bunny_set_key_response(key_event);
    bunny_loop(display.ds_win, 30, &display);
    bunny_stop(display.ds_win);
    return (0);
}
