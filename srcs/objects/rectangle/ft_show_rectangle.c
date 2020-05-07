/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_rectangle.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 16:28:11 by dboyer            #+#    #+#             */
/*   Updated: 2020/05/07 09:06:48 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void ft_show_rectangle(t_rectangle *rect, t_window *window)
{
	t_vector onset;
	t_vector offset;
	int i;

	i = 0;
	onset = rect->coordinate;
	offset = ft_vector(rect->coordinate.x, onset.y + rect->height, 0);
	while (i < rect->width)
	{
		ft_trace_column(onset, offset, window, rect->color);
		onset.x++;
		offset.x++;
		i++;
	}
}
