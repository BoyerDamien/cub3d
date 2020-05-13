/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_perp_dist.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/13 10:36:29 by dboyer            #+#    #+#             */
/*   Updated: 2020/05/13 10:42:53 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	ft_perp_dist(t_game *game, t_ray *ray)
{
	t_vector coordinate;

	coordinate = game->character.coordinate;
	if (ray->side == 0)
		return ((ray->point.x - coordinate.x + (1 - ray->step.x) / 2) / \
				ray->direction.x);
	else
		return ((ray->point.y - coordinate.y + (1 - ray->step.y) / 2) / \
				ray->direction.y);
}
