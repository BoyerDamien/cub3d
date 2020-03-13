/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_character_show.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 13:49:20 by dboyer            #+#    #+#             */
/*   Updated: 2020/03/12 18:30:18 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"


void ft_character_show(t_character *character, t_window window)
{
	int a;
	int r;
	t_vector coordinate;
	
	r = 3;
	a = 0;
	coordinate = ft_vector(0, 0, 0);
	while (r)
	{
		a = 0;
		while (a < 360)
		{
			coordinate.x = character->coordinate.x + r * sin(a);
			coordinate.y = character->coordinate.y + r * cos(a);
			window.draw(&window, coordinate, character->color);
			a++;
		}
		r--;
	}
}

