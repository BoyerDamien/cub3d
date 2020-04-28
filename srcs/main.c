/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 15:47:29 by dboyer            #+#    #+#             */
/*   Updated: 2020/04/28 18:03:34 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int get_map_width(t_element *element, int max_width)
{
	int width;
	char *content;
	
	width = 0;
	if (element){
		content = (char *)element->content;
		while (content[width])
			width++;
		if ( width > max_width )
			return (get_map_width(element->next, width));
		else 
			return (get_map_width(element->next, max_width));
	}
	return (max_width);
}


int ft_handle_events(int keycode, void *param){
	t_game *game;

	game = (t_game *)param;
	if (keycode == 65307){
		game->finish(game);
		exit(EXIT_SUCCESS);	
	}
	else if (keycode >= LEFT && keycode <= DOWN)
		game->character_move(game, keycode);
	else if (keycode == KEY_A)
		game->character_rotate(game, 'l');
	else if (keycode == KEY_Z)
		game->character_rotate(game, 'r');
	//mlx_clear_window(game->window.mlx_ptr, game->window.win_ptr);
	game->cast_ray(game);
	game->map_show(game);
	mlx_put_image_to_window(game->window.mlx_ptr, game->window.win_ptr, game->window.img.img_ptr, 0, 0);
	mlx_do_sync(game->window.mlx_ptr);
	return (0);
}



int main(int ac, char **av)
{
	ft_display_message("Check file ...");
	if (ac > 1 && ft_check_extension(av[1], ".cub"))
	{
		ft_check_resolution(av[1]);
		ft_check_texture(av[1]);
		ft_check_color(av[1]);
		//ft_test_map(av[1]);
		
		t_game game = ft_game(av[1]);
		mlx_hook(game.window.win_ptr, 2, 1L << 0, ft_handle_events, &game);
		mlx_do_sync(game.window.mlx_ptr);
		mlx_loop(game.window.mlx_ptr);
	}
	else{
		ft_display_error("No valid argument was provided", __func__);
		exit(EXIT_FAILURE);
	}
	return (0);
}


/*int key_center(int keycode, void *param)
{
	t_game *game;

	game = param;
	//ft_clear_image(&game->window);
	//printf("%i\n", keycode);
	if (keycode == 65307)
	{
		mlx_destroy_image(game->window.mlx_ptr, game->wall_texture_N.img_ptr);
		mlx_destroy_image(game->window.mlx_ptr, game->wall_texture_S.img_ptr);
		mlx_destroy_image(game->window.mlx_ptr, game->wall_texture_E.img_ptr);
		mlx_destroy_image(game->window.mlx_ptr, game->wall_texture_O.img_ptr);
		mlx_destroy_image(game->window.mlx_ptr, game->window.img.img_ptr);
		free(game->map.content);
		exit(0);
	}
	else if (keycode >= LEFT && keycode <= DOWN)
		game->character_move(game, keycode);
	else if (keycode == KEY_A)
		game->character_rotate(game, 'l');
	else if (keycode == KEY_Z)
		game->character_rotate(game, 'r');
	game->cast_ray(game);
	game->map_show(game);
	mlx_put_image_to_window(game->window.mlx_ptr, game->window.win_ptr, game->window.img.img_ptr, 0, 0);
	mlx_do_sync(game->window.mlx_ptr);
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
	ft_printf("Size = %d\n", win_size[0]);
	t_game game = ft_game(map, win_size);
	ft_printf("map = %s\n", game.map.content[0]);
	mlx_hook(game.window.win_ptr, 2, 1L << 0, key_center, &game);
	mlx_put_image_to_window(game.window.mlx_ptr, game.window.win_ptr, game.window.img.img_ptr, 0, 0);
	mlx_do_sync(game.window.mlx_ptr);
	mlx_loop(game.window.mlx_ptr);

	return (0);
}*/
