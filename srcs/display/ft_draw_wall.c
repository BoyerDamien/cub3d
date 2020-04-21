/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_wall.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/21 09:53:23 by dboyer            #+#    #+#             */
/*   Updated: 2020/04/21 15:49:55 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../includes/cub3d.h"

static t_color get_color(char *img, int x, int y, int size_line)
{
	int index;

	index = (int)(y * size_line + x * 4);
	return (ft_color(img[index], img[index + 1], img[index + 2]));
}

void ft_draw_wall(t_vector onset, t_vector offset, t_game *game, double l_ratio)
{

	t_vector direction;
	t_vector point;
	double dist;
	int cx;
	int cy;
	t_color text_color;

	direction = offset.direction(&offset, onset);
	dist = offset.dist(&offset, onset);
	while (dist > 0)
	{
		point = onset.add(&onset, direction.mul_scalar(&direction, dist));
		cx = (int)point.x % game->actual_text.height;
		cy = (int)point.y % game->actual_text.width;
		text_color = get_color(game->actual_text.img_data, cx, cy, game->actual_text.size_line);
		game->window.draw(&game->window, point, text_color.add_light(&text_color, text_color, l_ratio));
		dist--;
	}
}
