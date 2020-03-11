/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trace_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 16:38:26 by dboyer            #+#    #+#             */
/*   Updated: 2020/03/11 16:49:01 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void ft_trace_line(t_vector onset, t_vector offset, t_window window, t_color color)
{

	t_vector direction;
	t_vector point;
	double dist;

	direction = offset.direction(&offset, onset);
	point = offset.sub(&offset, onset);
	dist = point.length(&point);
	while (dist >= 0)
	{
		point = onset.add(&onset, direction.mul_scalar(&direction, dist));
		window.draw(&window, point, color);
		dist--;
	}
}
