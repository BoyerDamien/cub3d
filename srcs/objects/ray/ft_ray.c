/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ray.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/07 14:12:58 by dboyer            #+#    #+#             */
/*   Updated: 2020/05/13 15:04:46 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static inline void	update_side(t_ray *ray, t_game *game)
{
	t_vector coordinate;

	coordinate = game->character.coordinate;
	if (ray->direction.x < 0)
	{
		ray->step.x = -1;
		ray->sidedist.x = (coordinate.x - ray->point.x) * ray->deltadist.x;
	}
	else
	{
		ray->step.x = 1;
		ray->sidedist.x = (ray->point.x + 1.0 - coordinate.x) * \
		ray->deltadist.x;
	}
	if (ray->direction.y < 0)
	{
		ray->step.y = -1;
		ray->sidedist.y = (coordinate.y - ray->point.y) * ray->deltadist.y;
	}
	else
	{
		ray->step.y = 1;
		ray->sidedist.y = (ray->point.y + 1.0 - coordinate.y) * \
		ray->deltadist.y;
	}
}

static inline void	update(t_ray *ray, t_game *game, int x)
{
	t_vector direction;
	t_vector coordinate;
	t_vector plane;

	coordinate = game->character.coordinate;
	plane = game->character.plane;
	ray->cam_coordinate = 2 * x / (double)game->window.width - 1;
	direction = plane.mul_scalar(&plane, ray->cam_coordinate);
	ray->direction = direction.add(&direction, game->character.orientation);
	ray->point = ft_vector((int)coordinate.x, (int)coordinate.y, 0);
	ray->deltadist = ft_vector(fabs(1 / ray->direction.x),\
								fabs(1 / ray->direction.y), 0);
	update_side(ray, game);
}

static inline void	cast_one_ray(t_ray *ray, t_game *game)
{
	t_sprite	*sprite;
	double		dist;

	while (!ft_is_wall(game, ray->point.x, ray->point.y))
	{
		if (ft_is_sprite(game, ray->point.x, ray->point.y))
		{
			dist = ray->point.dist(&ray->point, game->character.coordinate);
			sprite = ft_sprite(game, ray);
			game->map.content[(int)ray->point.y][(int)ray->point.x] = 'a';
			ft_add_sprite(&game->sprites, sprite);
		}
		if (ray->sidedist.x < ray->sidedist.y)
		{
			ray->sidedist.x += ray->deltadist.x;
			ray->point.x += ray->step.x;
			ray->side = 0;
		}
		else
		{
			ray->sidedist.y += ray->deltadist.y;
			ray->point.y += ray->step.y;
			ray->side = 1;
		}
	}
}

t_ray				ft_ray(t_game *game)
{
	t_ray new;

	new.point = game->character.coordinate;
	new.direction = game->character.orientation;
	new.cast = cast_one_ray;
	new.update = update;
	return (new);
}
