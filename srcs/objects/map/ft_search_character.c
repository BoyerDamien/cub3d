#include "../../../includes/cub3d.h"

int ft_search_character(t_map *map, t_character *character)
{
	int i;
	int j;

	j = 0;
	while (map->content[j])
	{
		i = 0;
		while (map->content[i])
		{
			if (ft_cinset(map->content[j][i], "NESW"))
			{
                *character = ft_character(ft_vector(i, j, 0), 90, *map);
				return (1);
			}
			i++;
		}
		j++;
	}
	return (0);
}