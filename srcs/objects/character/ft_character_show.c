/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_character_show.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 13:49:20 by dboyer            #+#    #+#             */
/*   Updated: 2020/05/07 09:06:48 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


void ft_character_show(t_game *game)
{
	int a;
	int r;
	t_vector coordinate;
	
	r = 4;
	a = 0;
	coordinate = ft_vector(0, 0, 0);
	while (r)
	{
		a = 0;
		while (a < 360)
		{
			coordinate.x = game->character.coordinate.x * game->map.cube_width + game->map.coordinate.x + r * sin(a);
			coordinate.y = game->character.coordinate.y * game->map.cube_height + game->map.coordinate.y + r * cos(a);
			game->window.draw(&game->window, coordinate, game->character.color);
			a++;
		}
		r--;
	}
}

