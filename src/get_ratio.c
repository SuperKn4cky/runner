/*
 * E89 Pedagogical & Technical Lab
 * project:     tp_laser
 * created on:  2023-01-19 - 09:04 +0100
 * 1st author:  quentin.gimenez - quentin.gimenez
 * description: get ratio
 */

float get_ratio(int a, int b, int x)
{
    float ratio;
    float tmp;

    if (a == b) {
        return 1;
    }
    tmp = (b - a);
    return (ratio = (x - a) / tmp);
}
