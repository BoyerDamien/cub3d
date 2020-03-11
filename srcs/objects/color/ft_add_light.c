/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_light.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 10:19:31 by dboyer            #+#    #+#             */
/*   Updated: 2020/03/11 16:17:37 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

t_color ft_add_light(t_color *color, t_color light_color, double light_ratio)
{
	t_color new;

	new = ft_color(0, 0, 0);
	new.b = ((color->b / 255) + 0.1) * (light_color.b * light_ratio);
	new.g = ((color->g / 255) + 0.1) * (light_color.g * light_ratio);
	new.r = ((color->r / 255) + 0.1) * (light_color.r * light_ratio);
	new.b = new.b > 255 ? 255 : new.b;
	new.g = new.g > 255 ? 255 : new.g;
	new.r = new.r > 255 ? 255 : new.r;
	return (new);
}
