/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_ceil.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 12:06:45 by dboyer            #+#    #+#             */
/*   Updated: 2020/05/09 15:41:30 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_draw_ceil(t_vector onset, t_vector offset, t_game *game,\
t_color color)
{
	double	ratio;
	t_color	n_color;
	t_color	white;
	double	denom;

	white = ft_color(255, 255, 255);
	denom = game->win_center;
	while (onset.y <= offset.y)
	{
		ratio = (game->win_center - onset.y) / denom;
		n_color = color.add_light(&color, white, ratio);
		game->window.draw(&game->window, onset, n_color);
		onset.y++;
	}
}
