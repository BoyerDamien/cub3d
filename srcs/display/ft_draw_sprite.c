/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_sprite.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 16:03:00 by dboyer            #+#    #+#             */
/*   Updated: 2020/05/09 16:06:04 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static inline t_color	get_color(t_game *game, int x, int y)
{
	int		index;
	int		size_line;
	char	*img;

	size_line = game->sprite_texture.size_line;
	img = game->sprite_texture.img_data;
	index = (int)(y * size_line + x * 4);
	return (ft_color(img[index], img[index + 1], img[index + 2]));
}

static inline int		is_black(t_color *color)
{
	return (color->r == 0 && color->g == 0 && color->b == 0);
}

static inline int		compute_cx(t_game *game, t_sprite *sprite,\
t_vector point)
{
	double cx;

	cx = (point.x - (-sprite->width / 2 + sprite->screen_x));
	return ((256 * cx * game->sprite_texture.width / sprite->width) / 256);
}

static inline int		compute_cy(t_game *game, t_sprite *sprite, int y)
{
	int d;

	d = y * 256 - game->window.height * 128 + sprite->height * 128;
	return (((d * game->sprite_texture.height) / sprite->height) / 256);
}

void					ft_draw_sprite(t_sprite *sprite, t_game *game)
{
	t_color		text_color;
	int			cy;
	int			cx;
	int			y;
	t_vector	point;

	point = sprite->onset;
	while (point.x < sprite->offset.x)
	{
		y = point.y;
		cx = compute_cx(game, sprite, point);
		while (y < sprite->offset.y)
		{
			cy = compute_cy(game, sprite, y);
			text_color = get_color(game, cx, cy);
			text_color = text_color.add_light(&text_color, text_color,\
			sprite->ratio);
			if (!is_black(&text_color))
				game->window.draw(&game->window, ft_vector(point.x, y, 0),\
				text_color);
			y++;
		}
		point.x++;
	}
}
