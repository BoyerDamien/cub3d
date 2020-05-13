/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_character_show.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 13:49:20 by dboyer            #+#    #+#             */
/*   Updated: 2020/05/13 11:28:22 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_character_show(t_game *game)
{
	int			a;
	int			r;
	t_vector	coordinate;
	t_vector	cube;
	t_vector	angle;

	r = game->map.height * 0.03;
	cube = ft_vector(game->map.cube_width, game->map.cube_height, 0);
	angle = ft_vector(0, 0, 0);
	while (r)
	{
		a = 0;
		while (a < 360)
		{
			angle.update(&angle, sin(a), cos(a), 0);
			angle = angle.mul_scalar(&angle, r);
			coordinate = cube.mul(&cube, game->character.coordinate);
			coordinate = coordinate.add(&coordinate, game->map.coordinate);
			coordinate = coordinate.add(&coordinate, angle);
			game->window.draw(&game->window, coordinate, game->character.color);
			a++;
		}
		r--;
	}
}
