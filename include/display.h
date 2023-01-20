/*
 * E89 Pedagogical & Technical Lab
 * project:     runner
 * created on:  2022-12-06 - 10:31 +0100
 * 1st author:  quentin.gimenez - quentin.gimenez
 * description: structure
 */

#include <lapin.h>
#include "map.h"

#ifndef DISPLAY_H_
#define DISPLAY_H_

struct display {
    t_bunny_window *ds_win;
    t_bunny_pixelarray *ds_px;
    struct map map;
};

#endif // DISPLAY_H_
