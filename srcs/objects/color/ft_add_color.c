/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 10:57:21 by dboyer            #+#    #+#             */
/*   Updated: 2020/03/11 16:17:37 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

t_color ft_add_color(t_color *color1, t_color color2)
{
	t_color new;

	new = ft_color(0, 0, 0);
	new.r = (color1->r + color2.r);
	new.g = (color1->g + color2.g);
	new.b = (color1->b + color2.b);
	new.b = new.b > 255 ? 255 : new.b;
	new.g = new.g > 255 ? 255 : new.g;
	new.r = new.r > 255 ? 255 : new.r;
	return (new);
}
