/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_image.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 14:03:39 by dboyer            #+#    #+#             */
/*   Updated: 2020/03/11 16:17:37 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

t_image ft_image(t_window window, int img_size[2])
{
	t_image new;

	if (!(new.img_ptr = mlx_new_image(window.mlx_ptr, img_size[0], img_size[1])))
	{
		ft_printf("####\tERROR: cannot create image\t####");
		exit(EXIT_FAILURE);
	}
	if (!(new.img_data = mlx_get_data_addr(new.img_ptr, &new.bpp, &new.size_line, &new.endian)))
	{
		mlx_destroy_image(window.mlx_ptr, window.img.img_ptr);
		ft_printf("####\tERROR: cannot get image data\t####");
		exit(EXIT_FAILURE);
	}
	new.width = img_size[0];
	new.height = img_size[1];
	return (new);
}
