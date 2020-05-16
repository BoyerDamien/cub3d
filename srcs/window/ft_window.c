/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_window.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 15:20:41 by dboyer            #+#    #+#             */
/*   Updated: 2020/05/16 11:29:04 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_window	ft_window(double *width, double *height, char *name)
{
	t_window	new;
	int			x;
	int			y;

	if (!(new.mlx_ptr = mlx_init()))
	{
		ft_printf("####\tERROR: cannot init MLX\t####");
		exit(EXIT_FAILURE);
	}
	mlx_get_screen_size(new.mlx_ptr, &x, &y);
	*width = *width > x ? x : *width;
	*height = *height > y ? y : *height;
	if (!(new.win_ptr = mlx_new_window(new.mlx_ptr, *width, *height, name)))
	{
		ft_printf("####\tERROR: cannot init window\t####");
		exit(EXIT_FAILURE);
	}
	new.width = *width;
	new.height = *height;
	new.draw = put_pixel;
	new.img = ft_image(new, *width, *height);
	new.clear = ft_clear_image;
	return (new);
}
