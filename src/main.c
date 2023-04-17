/*
 * E89 Pedagogical & Technical Lab
 * project:     2022_runner
 * created on:  2022-09-29 - 14:39 +0200
 * 1st author:  Élise C. Philippe - eriizu
 * description: main
 */

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
    if (ds->player.level == 0) {
        if (keys[BKS_RETURN])
            ds->player.level = 1;
    } else {
        move(keys, ds);
        extra(keys, ds);
        rotate(keys, ds);
        pix_player_pos(ds);
        raycasting(ds);
        ds->map.map = map(ds);
        action_wall(ds);
    }
    if (ds->player.level == 3)
        return (EXIT_ON_SUCCESS);
    refresh(ds);
    return (GO_ON);
}


int main(void)
{
    struct display ds;

    ds.map.tile_size  = 100;
    ds.map.map        = map(&ds);
    ds.map.max_size   = MAX_SIZE(&ds);
    ds.player.level   = 0;
    reset_player_pos(&ds);
    ds.player.fov     = 90;
    ds.player.angle   = 0;
    ds.player.speed   = 0.05;
    ds.ds_win = bunny_start(960, 540, false, "fl: runner");
    ds.ds_px  = bunny_new_pixelarray(960, 540);
    bunny_set_key_response(key_event);
    bunny_set_mouse_visibility(ds.ds_win, false);
    bunny_set_loop_main_function(loop);
    bunny_loop(ds.ds_win, 60, &ds);
    bunny_stop(ds.ds_win);
    return (0);
}
