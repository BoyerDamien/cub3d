/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_show.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 13:00:35 by dboyer            #+#    #+#             */
/*   Updated: 2020/04/27 14:15:27 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"


void ft_map_show(t_game *game)
{
	int i;
	int j;
	t_rectangle rect;
	t_vector coordinate;

	i = 0;
	j = 0;
	while (game->map.content[j])
	{
		i = 0;
		while (game->map.content[j][i])
		{
			if (game->map.content[j][i] == '1')
			{
				coordinate = ft_vector(game->map.coordinate.x + i * game->map.cube_width, game->map.coordinate.y + j * game->map.cube_height, 0);
				rect = ft_rectangle(game->map.cube_width, game->map.cube_height, coordinate , game->map.color);
				rect.show(&rect, &game->window);
			}
			i++;
		}
		j++;
	}
	game->character_show(game);
}