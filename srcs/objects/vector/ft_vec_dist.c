#include "../../../includes/cub3d.h"

double ft_vec_dist(t_vector *vec1, t_vector vec2)
{
    t_vector diff;

    diff = vec1->sub(vec1, vec2);
    return (diff.length(&diff));
}