/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_sprite.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 16:03:00 by dboyer            #+#    #+#             */
/*   Updated: 2020/05/08 15:55:58 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static inline t_color get_color(char *img, int x, int y, int size_line)
{
	int index;

	index = (int)(y * size_line + x * 4);
	return (ft_color(img[index], img[index + 1], img[index + 2]));
}

static inline int is_black(t_color *color)
{
	return (color->r == 0 && color->g == 0 && color->b == 0);
}

void ft_draw_sprite(t_sprite *sprite, t_game *game)
{
	t_color text_color;
	int cy;
	int cx;
	int y;
	t_vector point;
	int d;

	point = sprite->onset;
	while (point.x < sprite->offset.x)
	{
		y = point.y;
		cx = (int)(256 * (point.x - (-sprite->width / 2 + sprite->screen_x)) * game->sprite_texture.width / sprite->width) / 256;
		while (y < sprite->offset.y)
		{
			d = (y) * 256 - game->window.height * 128 + sprite->height * 128;
          	cy = ((d * game->sprite_texture.height) / sprite->height) / 256;
			text_color = get_color(game->sprite_texture.img_data, cx, cy, game->sprite_texture.size_line);
			text_color = text_color.add_light(&text_color, text_color, sprite->ratio);
			if (!is_black(&text_color))
				game->window.draw(&game->window, ft_vector(point.x, y, 0), text_color);
			y++;
		}
		point.x++;
	}
}