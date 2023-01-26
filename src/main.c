/*
 * E89 Pedagogical & Technical Lab
 * project:     2022_runner
 * created on:  2022-09-29 - 14:39 +0200
 * 1st author:  Élise C. Philippe - eriizu
 * description: main
 */

#include <math.h>
#include <lapin.h>
#include "display.h"
#include "stu.h"

static void real_pos(struct display *ds)
{
    ds->player.pos.x *= ds->map.tile_size;
    ds->player.pos.y *= ds->map.tile_size;
    ds->player.pix = pos_from_accurate(&ds->player.pos);
    ds->player.pos.x /= ds->map.tile_size;
    ds->player.pos.y /= ds->map.tile_size;
}

static void angle(t_bunny_keysym keycode, struct display *ds)
{
    if (keycode == BKS_LEFT)
        ds->player.angle += 2;
    else if (keycode == BKS_RIGHT)
        ds->player.angle -= 2;
}

t_bunny_response key_event(t_bunny_event_state state,
                           t_bunny_keysym keycode,
                           void *data)
{
    struct display *ds;

    ds = data;
    if (state == GO_UP)
        return (GO_ON);
    if (keycode == BKS_ESCAPE)
        return (EXIT_ON_SUCCESS);
    fov(ds, BLACK, BLACK);
    move(keycode, ds);
    angle(keycode, ds);
    real_pos(ds);
    fov(ds, RED, GREEN);
    bunny_blit(&ds->ds_win->buffer, &ds->ds_px->clipable, NULL);
    bunny_display(ds->ds_win);
    return (GO_ON);
}

int main(void)
{
    int mx[6 * 8] = {
        1, 1, 1, 1, 1, 1, 1, 1,
        1, 0, 0, 0, 0, 0, 0, 1,
        1, 0, 0, 0, 0, 0, 0, 1,
        1, 0, 0, 1, 1, 1, 0, 1,
        1, 1, 0, 1, 1, 0, 0, 1,
        1, 1, 1, 1, 1, 1, 1, 1,
    };
    struct display display;

    display.map.width     = 8;
    display.map.height    = 6;
    display.map.tile_size = 100;
    display.map.map       = &mx[0];
    display.player.pos.x  = 2.5;
    display.player.pos.y  = 2.5;
    display.player.fov    = 45;
    display.player.angle  = 0;
    display.ds_win = bunny_start(display.map.width * display.map.tile_size,
                                 display.map.height * display.map.tile_size,
                                 false,
                                 "fl: runner");
    display.ds_px = bunny_new_pixelarray(display.ds_win->buffer.width,
                                         display.ds_win->buffer.height);
    display.player.pix    = pos_from_accurate(&display.player.pos);
    display.player.pix.x *= display.map.tile_size;
    display.player.pix.y *= display.map.tile_size;
    fill_wall(&display, WHITE);
    real_pos(&display);
    fov(&display, RED, GREEN);
    bunny_blit(&display.ds_win->buffer, &display.ds_px->clipable, NULL);
    bunny_display(display.ds_win);
    bunny_set_key_response(key_event);
    bunny_loop(display.ds_win, 30, &display);
    bunny_stop(display.ds_win);
    return (0);
}
