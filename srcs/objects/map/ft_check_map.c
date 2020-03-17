#include "../../../includes/cub3d.h"

t_vector ft_check_map(t_game *game, t_vector coordinate)
{
    int rx;
    int ry;

    rx = round((coordinate.x - game->character.map.coordinate.x) / game->character.map.cube_width);
	ry = round((coordinate.y - game->character.map.coordinate.y) / game->character.map.cube_height);
	rx = rx >= game->map.nx ? game->map.nx - 2 : rx;
	ry = ry >= game->map.ny ? game->map.ny - 2 : ry;
    return (ft_vector(rx, ry, 0));
}