/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minimap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 12:43:07 by dboyer            #+#    #+#             */
/*   Updated: 2020/05/07 19:07:21 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_map ft_minimap(char **map, size_t width, size_t height, t_vector coordinate)
{
	t_map new;

	new.content = map;
	new.width = width;
	new.height = height;
	new.coordinate = coordinate;
	new.cube_width = new.width * 0.1;
	new.cube_height = new.height * 0.1;
	new.color = ft_color(255, 255, 255);
	new.clear = ft_clear_map;
	return (new);
}
