/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_rectangle.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 16:28:11 by dboyer            #+#    #+#             */
/*   Updated: 2020/03/11 16:55:37 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

void ft_show_rectangle(t_rectangle *rect, t_window window)
{
	t_vector onset;
	t_vector offset;
	int i;

	i = 0;
	onset = rect->coordinate;
	offset = ft_vector(rect->coordinate.x + rect->width, onset.y, 0);
	while (i < rect->height)
	{
		ft_trace_line(onset, offset, window, rect->color);
		onset.y++;
		offset.y++;
		i++;
	}
}
