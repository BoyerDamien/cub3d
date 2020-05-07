/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ray.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/07 14:12:58 by dboyer            #+#    #+#             */
/*   Updated: 2020/05/07 14:52:25 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static inline void update_side(t_ray *ray, t_game *game)
{
    if (ray->direction.x < 0)
    {
        ray->step.x = -1;
        ray->sidedist.x = (game->character.coordinate.x - ray->point.x) * ray->deltadist.x; 
    }
    else
    {
        ray->step.x = 1;
        ray->sidedist.x = (ray->point.x + 1.0 - game->character.coordinate.x) * ray->deltadist.x;
    }
    if (ray->direction.y < 0)
    {
        ray->step.y = -1;
        ray->sidedist.y = (game->character.coordinate.y - ray->point.y) * ray->deltadist.y; 
    }
    else
    {
        ray->step.y = 1;
        ray->sidedist.y = (ray->point.y + 1.0 - game->character.coordinate.y) * ray->deltadist.y;
    }
}


static inline void update(t_ray *ray, t_game *game, int x)
{
    t_vector direction;

    ray->cam_coordinate = 2 * x / (double)game->window.width - 1;
    direction = game->character.plane.mul_scalar(&game->character.plane, ray->cam_coordinate);
    ray->direction = direction.add(&direction, game->character.orientation);
    ray->point = ft_vector((int)game->character.coordinate.x, (int)game->character.coordinate.y, 0);
    ray->deltadist = ft_vector(fabs(1 / ray->direction.x), fabs(1 / ray->direction.y), 0);
    update_side(ray, game);
}

static inline void cast_one_ray(t_ray *ray, t_game *game)
{
    while (!ft_is_wall(game, ray->point.x, ray->point.y))
    {
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

t_ray ft_ray(t_game *game)
{
    t_ray new;

    new.point = game->character.coordinate;
    new.direction = game->character.orientation;
    new.cast = cast_one_ray;
    new.update = update;
    return (new);
}