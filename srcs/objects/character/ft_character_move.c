/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_character_move.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 14:32:57 by dboyer            #+#    #+#             */
/*   Updated: 2020/03/12 18:16:20 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

static int get_map_height(char **map)
{
	int i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

void ft_character_move(t_character *character, int move, char **map_content)
{
	int rx;
	int ry;
	t_vector coordinate;
	int map_height;

	map_height  = get_map_height(map_content);
	coordinate = character->coordinate;
	if (move == RIGHT)
		coordinate.x += STEP;
	else if (move == LEFT)
		coordinate.x -= STEP;
	else if (move == DOWN)
		coordinate.y += STEP;
	else if (move == UP)
		coordinate.y -= STEP;
	rx = (coordinate.x - character->map_coordinate.x) / character->cube_width;
	ry = (coordinate.y - character->map_coordinate.y) / character->cube_height;
	ry = ry >= map_height ? map_height - 2 : ry;
	if (map_content[ry][rx] != '1')
		character->coordinate = coordinate;
}