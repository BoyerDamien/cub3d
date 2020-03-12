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

t_character ft_character(t_vector coordinate, double fov, double width, double height)
{
	t_character new;

	new.coordinate = coordinate;
	new.color = ft_color(255, 0, 0);
	new.cube_height = height;
	new.cube_width = width;
	new.fov = fov;
	new.show = ft_character_show;
	new.move = ft_character_move;
	return (new);
}
