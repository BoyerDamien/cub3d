/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rectangle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 16:23:08 by dboyer            #+#    #+#             */
/*   Updated: 2020/05/07 09:06:48 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_rectangle ft_rectangle(double width, double height, t_vector coordinate, t_color color)
{
	t_rectangle new;

	new.width = width;
	new.height = height;
	new.color = color;
	new.coordinate = coordinate;
	new.show = ft_show_rectangle;
	return (new);
}
