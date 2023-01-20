/*
 * E89 Pedagogical & Technical Lab
 * project:     tp_laser
 * created on:  2023-01-12 - 09:39 +0100
 * 1st author:  quentin.gimenez - quentin.gimenez
 * description: convert degre to radian
 */

#include <math.h>

double deg_to_rads(int degrees)
{
    double radian;

    if (degrees < 0) {
        while (degrees < - 360) {
            degrees += 360;
        }
        degrees = 360 - degrees;
    } else if (degrees > 360) {
        while (degrees > 360) {
            degrees -= 360;
        }
    }
    return (radian = (degrees * (2 * M_PI)) / 360);
}

