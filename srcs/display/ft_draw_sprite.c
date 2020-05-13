/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_sprite.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 16:03:00 by dboyer            #+#    #+#             */
/*   Updated: 2020/05/13 10:21:46 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static inline t_color	get_color(t_game *game, int x, int y, double ratio)
{
	int		index;
	int		size_line;
	char	*img;
	t_color color;

	size_line = game->sprite_texture.size_line;
	img = game->sprite_texture.img_data;
	index = (int)(y * size_line + x * 4);
	color = ft_color(img[index], img[index + 1], img[index + 2]);
	return (color.add_light(&color, color, ratio));
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

void					ft_draw_sprite(t_sprite *sprite,\
										t_game *game)
{
	t_color		text_color;
	t_vector	point;
	int			cx;
	int			y;

	point = sprite->onset;
	while (point.x < sprite->offset.x)
	{
		y = point.y - 1;
		cx = compute_cx(game, sprite, point);
		if (sprite->transform.y > 0 && point.x > 0\
			&& point.x < game->window.width
			&& sprite->transform.y < game->z_buffer[(int)point.x])
		{
			while (++y < sprite->offset.y)
			{
				text_color = get_color(game, cx, compute_cy(game, sprite, y),\
										sprite->ratio);
				if (!is_black(&text_color))
					game->window.draw(&game->window, ft_vector(point.x, y, 0),\
					text_color);
			}
		}
		point.x++;
	}
}
