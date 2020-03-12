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

static void correct_character_location(t_character *character, t_map *map)
{
	double rx;
	double ry;

	int x;
	int y;
	rx = character->coordinate.x / map->width;
	ry = character->coordinate.y / map->height;
	x = map->nx * rx;
	y = map->ny * ry;
	x = x >= map->nx ? map->nx - 1 : x;
	y = y >= map->ny ? map->ny - 1 : y;
	printf("x = %d -- y = %d\n", map->nx , map->ny);
	printf("x = %d -- y = %d\n", x , y);
	printf("Character = %c\n", map->content[y][x]);
	if (character->coordinate.x <= map->coordinate.x + map->cube_width)
		character->coordinate.x = map->coordinate.x + map->cube_width;
	if (character->coordinate.x >= map->coordinate.x + map->width - map->cube_width * 3)
		character->coordinate.x = map->coordinate.x + map->width - map->cube_width * 3;
	if (character->coordinate.y <= map->coordinate.y + map->cube_height)
		character->coordinate.y = map->coordinate.y + map->cube_width;
	if (character->coordinate.y >= map->coordinate.y + map->height - map->cube_height * 3)
		character->coordinate.y = map->coordinate.y + map->height - map->cube_height * 3;
}

void ft_map_show(t_map *map, t_window window)
{
	int i;
	int j;
	t_rectangle rect;
	t_vector coordinate;

	i = 0;
	j = 0;
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
	correct_character_location(&map->character, map);
	map->character.show(&map->character, window);
}