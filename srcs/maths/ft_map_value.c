#include "cub3d.h"

double ft_map_value(double val, double min1, double max1, double max2)
{
    double convert;

    convert = 1 - (max1 - val) / (max1 - min1);
    return (convert * max2);
}