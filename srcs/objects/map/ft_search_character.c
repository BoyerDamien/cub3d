#include "../../../includes/cub3d.h"

int ft_search_character(t_map *map, t_character *character)
{
	int i;
	int j;
    int x;
    int y;

	j = 0;
    x = 0;
    y = 0;
	while (map->content[j])
	{
		i = 0;
		while (map->content[i])
		{
			if (ft_cinset(map->content[j][i], "NESW"))
			{
                x = map->coordinate.x + i * map->cube_width;
                y = map->coordinate.y + j * map->cube_height;
                *character = ft_character(ft_vector(x, y, 0), 90, *map);
				return (1);
			}
			i++;
		}
		j++;
	}
	return (0);
}