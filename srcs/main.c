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
	t_game *game;
	t_map *map;

	game = param;
	map = &game->map;
	//ft_clear_image(&game->window);
	//printf("%i\n", keycode);
	if (keycode == 53)
	{
		mlx_destroy_image(game->window.mlx_ptr, game->window.img.img_ptr);
		free(game->map.content);
		exit(0);
	}
	else if (keycode >= LEFT && keycode <= UP)
		game->character_move(game, keycode);
	else if (keycode == KEY_A)
		game->character_rotate(game, 'l');	
	else if (keycode == KEY_Z)
		game->character_rotate(game, 'r');
	//game->map_show(game);
	game->cast_ray(game);
	//game->map_show(game);
	mlx_put_image_to_window(game->window.mlx_ptr, game->window.win_ptr, game->window.img.img_ptr, 0, 0);
	return (0);
}

int main(void)
{
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
	int win_size[2] = {WIN_WIDTH, WIN_HEIGHT};
	t_game game = ft_game(map, win_size);
	
	//void *img = mlx_xpm_file_to_image(game.window.mlx_ptr, "textures/grass.xpm", &width, &height);
	//mlx_destroy_image(game.window.mlx_ptr, img);
	//game.map_show(&game);

	mlx_hook(game.window.win_ptr, 2, 1L << 0, key_center, &game);
	mlx_put_image_to_window(game.window.mlx_ptr, game.window.win_ptr, game.window.img.img_ptr, 0, 0);
	mlx_loop(game.window.mlx_ptr);
	/*find_obstacles(&game.map, 0, 0);
	free(game.map.content);
	mlx_destroy_image(game.window.mlx_ptr, game.window.img.img_ptr);*/

	return (0);
}
