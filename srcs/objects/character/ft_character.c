/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_character.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 13:46:36 by dboyer            #+#    #+#             */
/*   Updated: 2020/05/13 10:49:25 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static inline t_vector	plane_orientation(double orientation)
{
	t_vector	result;
	double		coeff;

	coeff = tan(ft_degree_to_rad(FOV) / 2);
	result = ft_vector(0, 0, 0);
	if (orientation == 90)
		result.y = -coeff;
	else if (orientation == 270)
		result.y = coeff;
	else if (orientation == 0)
		result.x = coeff;
	else if (orientation == 180)
		result.x = -coeff;
	return (result);
}

t_character				ft_character(t_vector coordinate,\
						double orientation, t_map map)
{
	t_character new;
	double		rad_orientation;

	rad_orientation = ft_degree_to_rad(orientation);
	new.coordinate = coordinate;
	new.map = map;
	new.color = ft_color(255, 0, 0);
	new.fov = ft_degree_to_rad(FOV);
	new.orientation = ft_vector(sin(rad_orientation), cos(rad_orientation), 0);
	new.plane = plane_orientation(orientation);
	return (new);
}
