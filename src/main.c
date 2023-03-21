/*
 * E89 Pedagogical & Technical Lab
 * project:     2022_runner
 * created on:  2022-09-29 - 14:39 +0200
 * 1st author:  Élise C. Philippe - eriizu
 * description: main
 */


#include "display.h"
#include "stu.h"

static void pix_player_pos(struct display *ds)
{
    ds->player.pos.x *= ds->map.tile_size;
    ds->player.pos.y *= ds->map.tile_size;
    ds->player.pix = pos_from_accurate(&ds->player.pos);
    ds->player.pos.x /= ds->map.tile_size;
    ds->player.pos.y /= ds->map.tile_size;
}

void refresh(struct display *ds)
{
    bunny_blit(&ds->ds_win->buffer, &ds->ds_px->clipable, NULL);
    bunny_display(ds->ds_win);
}

t_bunny_response key_event(t_bunny_event_state state,
                           t_bunny_keysym keycode,
                           void *data)
{
    (void) data;
    if (state == GO_UP)
        return (GO_ON);
    if (keycode == BKS_ESCAPE)
        return (EXIT_ON_SUCCESS);
    return (GO_ON);
}

t_bunny_response loop(void *data)
{
    struct display *ds;
    const bool *keys;

    ds = data;
    keys = bunny_get_keyboard();
    move(keys, ds);
    rotate(keys, ds);
    pix_player_pos(ds);
    deux_d(ds);
    trois_d(ds, 1);
    refresh(ds);
    return (GO_ON);
}


int main(void)
{
    int mx[16 * 16] = {
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1,
        1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1,
        1, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
        1, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1,
        1, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1,
        1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1,
        1, 1, 1, 1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1,
        1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1,
        1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1,
        1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1,
        1, 0, 0, 0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1,
        1, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1,
        1, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
        1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1,
    };
    struct display ds;

    ds.map.width     = 16;
    ds.map.height    = 16;
    ds.map.tile_size = 100;
    ds.map.map       = &mx[0];
    ds.player.pos.x  = 3.5;
    ds.player.pos.y  = 1.5;
    ds.player.fov    = 45;
    ds.player.angle  = 0;
    ds.ds_win = bunny_start(ds.map.width * ds.map.tile_size,
                            ds.map.height * ds.map.tile_size,
                            false,
                            "fl: runner");
    ds.ds_px = bunny_new_pixelarray(ds.ds_win->buffer.width,
                                    ds.ds_win->buffer.height);
    ds.max_size = MAX_SIZE(&ds);
    clear_pixelarray(ds.ds_px, BLACK);
    pix_player_pos(&ds);
    deux_d(&ds);
    trois_d(&ds, 1);
    refresh(&ds);
    bunny_set_key_response(key_event);
    bunny_set_loop_main_function(loop);
    bunny_loop(ds.ds_win, 30, &ds);
    bunny_stop(ds.ds_win);
    return (0);
}
