/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_show.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 13:00:35 by dboyer            #+#    #+#             */
/*   Updated: 2020/03/12 18:34:13 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

void ft_map_show(t_map *map, t_window window)
{
	int i;
	int j;
	t_rectangle rect;
	t_vector coordinate;

	i = 0;
	j = 0;
	window.clear(&window);
	while (map->content[j])
	{
		i = 0;
		while (map->content[i])
		{
			if (map->content[j][i] == '1')
			{
				coordinate = ft_vector(map->coordinate.x + i * map->cube_width, map->coordinate.y + j * map->cube_height, 0);
				rect = ft_rectangle(map->cube_width, map->cube_height, coordinate , map->color);
				rect.show(&rect, window);
			}
			else
			{
				coordinate = ft_vector(map->coordinate.x + i * map->cube_width, map->coordinate.y + j * map->cube_height, 0);
				rect = ft_rectangle(map->cube_width, map->cube_height, coordinate , ft_color(0, 0, 0));
				rect.show(&rect, window);
			}
			i++;
		}
		j++;
	}
	map->character.show(&map->character, window);
	map->character.cast_ray(&map->character, map->content, window);
}