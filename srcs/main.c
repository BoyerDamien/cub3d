/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 15:47:29 by dboyer            #+#    #+#             */
/*   Updated: 2020/03/11 18:11:06 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int key_center(int keycode, void *param)
{
	//(void)param;
	ft_printf("%i\n", keycode);
	if (keycode == 53)
	{
		mlx_destroy_image(((t_window *)param)->mlx_ptr, ((t_window *)param)->img.img_ptr);
		exit(0);
	}
	return (0);
}

int main(void)
{
	t_window window;
	int win_size[2] = {1200, 1200};
	int vp_size[2] = {1200, 1200};
	int worldMap[24][24]=
		{
				{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
				{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
				{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
				{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
				{1,0,0,0,0,0,1,1,1,1,1,0,0,0,0,1,0,1,0,1,0,0,0,1},
				{1,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1},
				{1,0,0,0,0,0,1,0,0,0,1,0,0,0,0,1,0,0,0,1,0,0,0,1},
				{1,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1},
				{1,0,0,0,0,0,1,1,0,1,1,0,0,0,0,1,0,1,0,1,0,0,0,1},
				{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
				{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
				{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
				{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
				{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
				{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
				{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
				{1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
				{1,1,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
				{1,1,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
				{1,1,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,'N',0,0,1},
				{1,1,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
				{1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
				{1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
				{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
		};
	int i;
	int j;
	int width;
	int height;
	t_vector coordinate;
	double block_size;
	t_rectangle rect;
	t_color color;
	t_color player;

	player = ft_color(255,0,0);
	color = ft_color(255,255,255);
	i = 0;
	j = 0;
	width = 200;
	height = 200;
	coordinate = ft_vector(50, 50, 0);
	block_size = 200 / 24;
	window = ft_window(win_size, vp_size, "cub3d");
	while (j < 24)
	{
		i = 0;
		while (i < 24)
		{
			if (worldMap[j][i] == 1)
			{
				rect = ft_rectangle(block_size, block_size, ft_vector(coordinate.x + i * block_size, coordinate.y + j * block_size, 0) ,color);
				rect.show(&rect, window);
			}
			else if (worldMap[j][i] == 'N')
			{
				rect = ft_rectangle(block_size, block_size, ft_vector(coordinate.x + i * block_size, coordinate.y + j * block_size, 0) ,player);
				rect.show(&rect, window);
			}
			i++;
		}
		j++;
	}
	mlx_put_image_to_window(window.mlx_ptr, window.win_ptr, window.img.img_ptr, 0, 0);
	mlx_key_hook(window.win_ptr, key_center, &window);
	mlx_loop(window.mlx_ptr);
	/*int x;
	int y;
	t_rectangle rect;

	x = 0;
	y = 0;
	color = ft_color(100, 100, 100);
	window = ft_window(win_size, vp_size, "cub3d");
	rect = ft_rectangle(100,100, ft_vector(550,550,0), ft_color(255,0,0));
	rect.show(&rect, window);
	mlx_put_image_to_window(window.mlx_ptr, window.win_ptr, window.img.img_ptr, 0, 0);
	mlx_key_hook(window.win_ptr, key_center, &window);
	mlx_loop(window.mlx_ptr);*/
	return (0);
}
