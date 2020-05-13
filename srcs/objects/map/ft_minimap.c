/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minimap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 12:43:07 by dboyer            #+#    #+#             */
/*   Updated: 2020/05/13 11:51:35 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_map	ft_minimap(char **map, size_t width, size_t height, t_vector coordinate)
{
	t_map new;

	new.content = map;
	new.width = width;
	new.height = height;
	new.coordinate = coordinate;
	new.color = ft_color(255, 255, 255);
	new.clear = ft_clear_map;
	if (new.width * 0.05 <= new.height * 0.05)
	{
		new.cube_width = new.width * 0.05;
		new.cube_height = new.width * 0.05;
	}
	else
	{
		new.cube_width = new.height * 0.05;
		new.cube_height = new.height * 0.05;
	}
	return (new);
}
