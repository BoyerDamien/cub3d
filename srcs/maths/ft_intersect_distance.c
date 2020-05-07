#include "cub3d.h"

double ft_intersect_distance(t_vector point_dir, t_vector origin_dir)
{
    return (point_dir.dot(&point_dir, origin_dir));
}