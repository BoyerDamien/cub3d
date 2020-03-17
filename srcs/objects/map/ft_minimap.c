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

static int map_height(char **map)
{
	int i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

t_map ft_minimap(char **map, size_t width, size_t height, t_vector coordinate)
{
	t_map new;

	new.content = map;
	new.width = width;
	new.height = height;
	new.coordinate = coordinate;
	new.nx = ft_strlen(map[0]);
	new.cube_width = new.width / new.nx;
	new.ny = map_height(map);
	new.cube_height = new.height / new.ny;
	new.color = ft_color(255, 255, 255);
	return (new);
}
