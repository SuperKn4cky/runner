/*
* E89 Pedagogical & Technical Lab
 * project:     runner
 * created on:  2023-03-06 - 09:45 +0100
 * 1st author:  user - user
 * description: 3d
 */

#include <stu.h>

static void sky_ground(struct display *ds)
{
    int width;
    int height;
    int total;
    int i;
    unsigned int *pix;

    width = ds->ds_px_3d->clipable.clip_width;
    height = ds->ds_px_3d->clipable.clip_height;
    total = width * height;
    i = total / 2;
    pix = (unsigned int *) ds->ds_px_3d->pixels;
    while (total > i) {
        pix[total] = BLACK;
        total -= 1;
    }
    while (i > 0) {
        pix[i] = BLUE;
        i -= 1;
    }
}

void trois_d(struct display *ds, double angle)
{
    sky_ground(ds);
    //size_wall(ds);
    (void) angle;
    (void) ds;
}
