/*
 * E89 Pedagogical & Technical Lab
 * project:     tp_laser
 * created on:  2023-01-19 - 09:05 +0100
 * 1st author:  quentin.gimenez - quentin.gimenez
 * description: get value
 */

int get_value(int a, int b, float ratio)
{
    float tmp;
    int value;

    tmp = (ratio * (b - a) + a);
    value = tmp;
    return (value);
}

