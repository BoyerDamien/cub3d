/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_light.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 10:19:31 by dboyer            #+#    #+#             */
/*   Updated: 2020/05/07 09:06:48 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_color ft_add_light(t_color *color, t_color light_color, double light_ratio)
{
	t_color new;

	new = ft_color(0, 0, 0);
	new.b = color->b  * light_color.b * light_ratio / 255;
	new.g = color->g  * light_color.g * light_ratio / 255;
	new.r = color->r  * light_color.r * light_ratio / 255;
	new.b = new.b > color->b ? color->b : new.b;
	new.g = new.g > color->g ? color->g : new.g;
	new.r = new.r > color->r ? color->r : new.r;
	return (new);
}
