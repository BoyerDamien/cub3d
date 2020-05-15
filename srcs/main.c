/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 15:47:29 by dboyer            #+#    #+#             */
/*   Updated: 2020/05/15 19:00:46 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_save(t_game *game)
{
	ft_display_message("Saving in progress...");
	ft_write_bmp_file(game);
	ft_display_process_status("Saving", "ok");
}

int			ft_handle_events(int keycode, void *param)
{
	t_game *game;

	game = (t_game *)param;
	if (keycode == ESCAPE)
	{
		game->finish(game);
		exit(EXIT_SUCCESS);
	}
	else if (keycode >= LEFT && keycode <= UP)
		game->character_move(game, keycode);
	else if (keycode == KEY_A)
		game->character_rotate(game, 'l');
	else if (keycode == KEY_Z)
		game->character_rotate(game, 'r');
	mlx_clear_window(game->window.mlx_ptr, game->window.win_ptr);
	ft_cast_ray(game);
	game->map_show(game);
	mlx_put_image_to_window(game->window.mlx_ptr, game->window.win_ptr,\
							game->window.img.img_ptr, 0, 0);
	mlx_do_sync(game->window.mlx_ptr);
	return (0);
}

static int	ft_handle_destruction(int keycode, void *param)
{
	(void)keycode;
	(void)param;
	ft_display_message("Finish game...");
	exit(EXIT_SUCCESS);
	return (0);
}

static void	parse(char *arg)
{
	ft_check_resolution(arg);
	ft_check_texture(arg);
	ft_check_color(arg);
	ft_check_character(arg);
	ft_test_map(arg);
}

int			main(int ac, char **av)
{
	t_game game;

	ft_display_message("Check file ...");
	if (ac > 1 && ft_check_extension(av[1], ".cub"))
	{
		parse(av[1]);
		game = ft_game(av[1]);
		ft_cast_ray(&game);
		game.map_show(&game);
		if (ac >= 2 && ft_str_isequal(av[2], "--save"))
			ft_save(&game);
		else
		{
			mlx_put_image_to_window(game.window.mlx_ptr, game.window.win_ptr,\
							game.window.img.img_ptr, 0, 0);
			mlx_hook(game.window.win_ptr, 2, 1L << 0, ft_handle_events, &game);
			mlx_hook(game.window.win_ptr, 17, 1L << 17,\
						ft_handle_destruction, &game);
			mlx_loop(game.window.mlx_ptr);
		}
	}
	else
		ft_display_error("No valid argument was provided", __func__);
	return (0);
}
