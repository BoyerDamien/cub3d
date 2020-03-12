/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minimap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 12:43:07 by dboyer            #+#    #+#             */
/*   Updated: 2020/03/12 18:28:22 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

static t_character search_character(t_map *map)
{
	int i;
	int j;
	t_character new;
	t_vector coordinate;

	j = 0;
	while (map->content[j])
	{
		i = 0;
		while (map->content[i])
		{
			if (ft_cinset(map->content[j][i], "NESW"))
			{
				coordinate = ft_vector(map->coordinate.x + i * map->cube_width, map->coordinate.y + j * map->cube_height, 0);
				new = ft_character(coordinate, 90, map->cube_width, map->cube_height);
				return (new);
			}
			i++;
		}
		j++;
	}
	return (ft_character(ft_vector(0, 0, 0), 0, 0, 0));
}

t_map ft_minimap(char **map, size_t width, size_t height, t_vector coordinate)
{
	t_map new;
	int i;

	i = 0;
	new.content = map;
	new.width = width;
	new.height = height;
	new.coordinate = coordinate;
	new.nx = ft_strlen(map[0]);
	new.cube_width = new.width / new.nx;
	while (map[i])
		i++;
	new.ny = i;
	new.cube_height = new.height / new.ny;
	new.color = ft_color(255, 255, 255);
	new.show = ft_map_show;
	new.character = search_character(&new);
	return (new);
}
