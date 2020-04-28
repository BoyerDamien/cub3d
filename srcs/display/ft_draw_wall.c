/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_wall.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/21 09:53:23 by dboyer            #+#    #+#             */
/*   Updated: 2020/04/28 19:46:15 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../includes/cub3d.h"

static inline t_color get_color(char *img, int x, int y, int size_line)
{
	int index;

	index = (int)(y * size_line + x * 4);
	return (ft_color(img[index], img[index + 1], img[index + 2]));
}

void ft_draw_wall(t_vector onset, t_vector offset, t_game *game, double l_ratio)
{
	double cy;
	t_color text_color;
	t_vector point;
	int y;
	(void)l_ratio;

	y = 0;
	point = ft_vector(onset.x, onset.y, 0);
	while (point.y <= offset.y){
		cy = y / (offset.y - onset.y) * game->actual_text.height;
		text_color = get_color(game->actual_text.img_data, game->text_column, cy, game->actual_text.size_line);
		text_color = text_color.add_light(&text_color, text_color, l_ratio);
		game->window.draw(&game->window, point, text_color);
		point.y++;
		y++;
	}
}
