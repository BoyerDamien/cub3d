#include "../../../includes/cub3d.h"

int ft_check_map(t_vector point, t_character *character, char **map_content)
{
    int rx;
    int ry;

    rx = (point.x - character->map_coordinate.x) / character->cube_width;
	ry = (point.y - character->map_coordinate.y) / character->cube_height;
	if (map_content[ry][rx] != '1')
		return (1);
    return (0);
}