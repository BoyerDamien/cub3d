#include "cub3d.h"

double ft_degree_to_rad(double angle)
{
    if (angle >= 0 && angle <= 360)
        return (angle * M_PI / 180);
    return (0);
}