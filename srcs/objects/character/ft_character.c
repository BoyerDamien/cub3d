/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_character.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 13:46:36 by dboyer            #+#    #+#             */
/*   Updated: 2020/03/12 15:06:49 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

t_character ft_character(t_vector coordinate, double orientation, t_map map)
{
	t_character new;

	new.coordinate = coordinate;
	new.map = map;
	new.color = ft_color(255, 0, 0);
	new.fov = ft_degree_to_rad(FOV);
	new.orientation = ft_degree_to_rad(orientation);
	new.show = ft_character_show;
	return (new);
}
