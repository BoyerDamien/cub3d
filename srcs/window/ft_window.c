/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_window.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 15:20:41 by dboyer            #+#    #+#             */
/*   Updated: 2020/05/07 09:06:48 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_window	ft_window(int width, int height, char *name)
{
	t_window new;

	if (!(new.mlx_ptr = mlx_init()))
	{
		ft_printf("####\tERROR: cannot init MLX\t####");
		exit(EXIT_FAILURE);
	}
	if (!(new.win_ptr = mlx_new_window(new.mlx_ptr, width, height, name)))
	{
		ft_printf("####\tERROR: cannot init window\t####");
		exit(EXIT_FAILURE);
	}
	new.width = width;
	new.height = height;
	new.draw = put_pixel;
	new.img = ft_image(new, width, height);
	new.clear = ft_clear_image;
	return (new);
}
