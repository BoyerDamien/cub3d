/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_window.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 15:20:41 by dboyer            #+#    #+#             */
/*   Updated: 2020/03/11 16:17:37 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

t_window	ft_window(int win_size[2], int img_size[2], char *name)
{
	t_window new;

	if (!(new.mlx_ptr = mlx_init()))
	{
		ft_printf("####\tERROR: cannot init MLX\t####");
		exit(EXIT_FAILURE);
	}
	if (!(new.win_ptr = mlx_new_window(new.mlx_ptr, win_size[0], win_size[1], name)))
	{
		ft_printf("####\tERROR: cannot init window\t####");
		exit(EXIT_FAILURE);
	}
	new.width = win_size[0];
	new.height = win_size[1];
	new.draw = put_pixel;
	new.img = ft_image(new, img_size);
	return (new);
}
