/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_image.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 14:03:39 by dboyer            #+#    #+#             */
/*   Updated: 2020/05/13 10:30:42 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_image	ft_image(t_window window, int width, int height)
{
	t_image new;

	if (!(new.img_ptr = mlx_new_image(window.mlx_ptr, width, height)))
	{
		ft_display_error("Cannot create image", __func__);
		exit(EXIT_FAILURE);
	}
	if (!(new.img_data = mlx_get_data_addr(new.img_ptr, &new.bpp,\
			&new.size_line, &new.endian)))
	{
		mlx_destroy_image(window.mlx_ptr, window.img.img_ptr);
		ft_display_error("Cannot get image data", __func__);
		exit(EXIT_FAILURE);
	}
	new.width = width;
	new.height = height;
	return (new);
}
