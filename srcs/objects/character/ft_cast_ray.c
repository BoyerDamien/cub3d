/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cast_ray.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 11:46:22 by dboyer            #+#    #+#             */
/*   Updated: 2020/05/13 10:46:34 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static inline void	display(t_list *list, t_game *game)
{
	t_sprite *sprite;

	if (list->size > 0)
	{
		sprite = (t_sprite *)list->last->content;
		ft_draw_sprite(sprite, game);
		game->map.content[(int)sprite->point.y][(int)sprite->point.x] = '2';
		free(sprite);
		list->remove(list, list->last);
		display(list, game);
	}
}

static inline void	render(t_game *game, double dist, int x)
{
	double		height;
	t_vector	onset;
	t_vector	offset;
	int			win_height;

	win_height = game->window.height;
	if (dist >= 0)
	{
		height = dist > 0 ? win_height / dist : win_height;
		height = height > win_height ? win_height : height;
		if (height <= win_height)
		{
			onset = ft_vector(x, game->win_center - height / 2, 0);
			offset = ft_vector(x, game->win_center + height / 2, 0);
			ft_draw_ceil(ft_vector(x, 0, 0), onset, game, game->ceil_color);
			ft_draw_wall(onset, offset, game, 255 / dist * LIGHT_RATIO);
			onset = ft_vector(x, win_height, 0);
			ft_draw_ground(offset, onset, game, game->floor_color);
		}
	}
}

void				ft_cast_ray(t_game *game)
{
	t_ray	ray;
	double	dist;
	int		x;

	x = 0;
	ray = ft_ray(game);
	while (x < game->window.width)
	{
		ray.update(&ray, game, x);
		ray.cast(&ray, game);
		dist = ft_perp_dist(game, &ray);
		game->z_buffer[x] = dist;
		ft_choose_texture(&ray, game, dist);
		render(game, dist, x);
		x++;
	}
	if (game->sprites.size > 0)
		display(&game->sprites, game);
}
