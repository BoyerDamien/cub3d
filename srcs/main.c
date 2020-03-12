/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 15:47:29 by dboyer            #+#    #+#             */
/*   Updated: 2020/03/12 18:27:58 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int key_center(int keycode, void *param)
{
	t_map *map;

	map = param;
	ft_printf("%i\n", keycode);
	if (keycode == 53)
	{
		mlx_destroy_image(map->window.mlx_ptr, map->window.img.img_ptr);
		free(map->content);
		exit(0);
	}
	else if (keycode >= LEFT && keycode <= UP)
	{
		map->character.move(&map->character, keycode);
		map->show(map, map->window);
		mlx_put_image_to_window(map->window.mlx_ptr, map->window.win_ptr, map->window.img.img_ptr, 0, 0);
	}
	return (0);
}

int main(void)
{
	t_window window;
	int win_size[2] = {1200, 1200};
	int vp_size[2] = {1200, 1200};
	t_map minimap;
	char *worldMap[25]=
		{
				"111111111111111111111111",
				"100000000000000000000001",
				"100000000000000000000001",
				"100000000000000000000001",
				"100000111110000101010001",
				"100000100010000000000001",
				"100000100010000100010001",
				"100000100010000000000001",
				"100000110110000101010001",
				"100000000000000000000001",
				"100000000000000000000001",
				"100000000000000000000001",
				"100000000000000000000001",
				"100000000000000000000001",
				"100000000000000000000001",
				"100000000000000000000001",
				"111111111000000000000001",
				"110100001000000000000001",
				"110000101000000000000001",
				"11010000100000000000N001",
				"110111111000000000000001",
				"110000000000000000000001",
				"111111111000000000000001",
				"111111111111111111111111",
				NULL
		};
	int i = 0;
	char **map = (char **)malloc(sizeof(char *) * 25);
	while (worldMap[i])
	{
		map[i] = worldMap[i];
		i++;
	}
	map[i] = NULL;


	minimap = ft_minimap(map, 400, 400, ft_vector(100, 100, 0));
	window = ft_window(win_size, vp_size, "cub3d");
	minimap.window = window;
	minimap.show(&minimap, window);


	mlx_put_image_to_window(window.mlx_ptr, window.win_ptr, window.img.img_ptr, 0, 0);
	mlx_key_hook(window.win_ptr, key_center, &minimap);
	mlx_loop(window.mlx_ptr);
	return (0);
}
