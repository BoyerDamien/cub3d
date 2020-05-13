/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_show.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 13:00:35 by dboyer            #+#    #+#             */
/*   Updated: 2020/05/13 11:48:04 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_map_show(t_game *game)
{
	t_vector	index;
	t_rectangle	rect;
	t_vector	coordinate;
	t_vector	cube;

	index = ft_vector(0, 0, 0);
	coordinate = ft_vector(0, 0, 0);
	cube = ft_vector(game->map.cube_width, game->map.cube_height, 0);
	while (game->map.content[(int)index.y])
	{
		while (game->map.content[(int)index.y][(int)index.x])
		{
			if (game->map.content[(int)index.y][(int)index.x] == '1')
			{
				coordinate = cube.mul(&cube, index);
				coordinate = coordinate.add(&coordinate, game->map.coordinate);
				rect = ft_rectangle(cube.x, cube.y,\
						coordinate, game->map.color);
				rect.show(&rect, &game->window);
			}
			index.x++;
		}
		index.update(&index, 0, index.y + 1, 0);
	}
	game->character_show(game);
}
