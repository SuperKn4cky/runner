/*
 * E89 Pedagogical & Technical Lab
 * project:     tp_laser
 * created on:  2023-01-12 - 09:39 +0100
 * 1st author:  quentin.gimenez - quentin.gimenez
 * description: convert degre to radian
 */

#include <math.h>

double deg_to_rads(double degrees)
{
    return (degrees * (2 * M_PI)) / 360;
}

