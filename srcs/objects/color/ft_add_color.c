/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 10:57:21 by dboyer            #+#    #+#             */
/*   Updated: 2020/04/21 14:25:58 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

t_color ft_add_color(t_color *color1, t_color color2)
{
	t_color new;

	new = ft_color(0, 0, 0);
	new.r = (color1->r / 255) * (color2.r / 255) * 255;
	new.g = (color1->g / 255) * (color2.g / 255) * 255;
	new.b = (color1->b / 255) * (color2.b / 255) * 255;
	return (new);
}
