/*
 * E89 Pedagogical & Technical Lab
 * project:     tp_laser
 * created on:  2023-01-19 - 09:04 +0100
 * 1st author:  quentin.gimenez - quentin.gimenez
 * description: get ratio
 */

static int calc_diff(int a, int b)
{
    if (a > b)
        return (a - b);
    return (b - a);
}

static int get_min(int a, int b)
{
    if (a < b) {
        return (a);
    }
    return (b);
}

float get_ratio(int a, int b, int x)
{
    /*
     * float ratio;
     * float tmp;
     * 
     * if (a == b) {
     *     return 1;
     * }
     * tmp = (b - a);
     * return (ratio = (x - a) / tmp);
     */
    int nb_min;
    int diff;
    float ratio;

    nb_min = get_min(a, b);
    a -= (nb_min - 1);
    b -= (nb_min - 1);
    x -= (nb_min - 1);
    diff = calc_diff(a, b);
    ratio = (float) (x - 1) / diff;
    return (ratio);
}

