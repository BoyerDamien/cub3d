#include "../../../includes/cub3d.h"


double choose_orientation(char c){
	if (c == 'E')
		return (90);
	else if ( c == 'N')
		return (180);
	else if ( c == 'W')
		return (270);
	return (0);
}

int ft_search_character(t_map *map, t_character *character)
{
	int i;
	int j;
	double orientation;

	j = 0;
	while (map->content[j])
	{
		i = 0;
		while (map->content[j][i])
		{
			if (ft_cinset(map->content[j][i], "NESW"))
			{
				orientation = choose_orientation(map->content[j][i]);
                *character = ft_character(ft_vector(i, j, 0), orientation, *map);
				return (1);
			}
			i++;
		}
		j++;
	}
	return (0);
}