#include "../../../includes/cub3d.h"

t_vector ft_check_map(t_game *game, t_vector coordinate)
{
    int rx;
    int ry;

	rx = coordinate.x >= game->map.nx ? game->map.nx - 2 : coordinate.x;
	ry = coordinate.y >= game->map.ny ? game->map.ny - 2 : coordinate.y;
    return (ft_vector(rx, ry, 0));
}