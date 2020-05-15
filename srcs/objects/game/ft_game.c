/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/07 14:10:42 by dboyer            #+#    #+#             */
/*   Updated: 2020/05/15 10:35:20 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void		finish(t_game *game)
{
	mlx_destroy_image(game->window.mlx_ptr, game->wall_texture_n.img_ptr);
	mlx_destroy_image(game->window.mlx_ptr, game->wall_texture_s.img_ptr);
	mlx_destroy_image(game->window.mlx_ptr, game->wall_texture_e.img_ptr);
	mlx_destroy_image(game->window.mlx_ptr, game->wall_texture_o.img_ptr);
	mlx_destroy_image(game->window.mlx_ptr, game->sprite_texture.img_ptr);
	mlx_destroy_image(game->window.mlx_ptr, game->window.img.img_ptr);
	mlx_destroy_window(game->window.mlx_ptr, game->window.win_ptr);
	game->map.clear(&game->map);
	free(game->z_buffer);
}

static void		init_method(t_game *game)
{
	game->map_show = ft_map_show;
	game->character_move = ft_character_move;
	game->character_rotate = ft_character_rotate;
	game->character_show = ft_character_show;
	game->finish = finish;
}

t_game			ft_game(char *path)
{
	t_game		new;
	t_vector	window_dimensions;
	char		**map;
	t_vector	size;

	init_method(&new);
	window_dimensions = ft_get_window_dimensions(path);
	size = window_dimensions.mul_scalar(&window_dimensions, 0.1);
	new.window = ft_window(window_dimensions.x, window_dimensions.y, GAME_NAME);
	map = ft_map_list_to_char(path);
	new.map = ft_minimap(map, size.x, size.y, ft_vector(0, 0, 0));
	ft_search_character(&new.map, &new.character);
	new.wall_texture_n = ft_create_texture_from_file(path, "NO", &new.window);
	new.wall_texture_s = ft_create_texture_from_file(path, "SO", &new.window);
	new.wall_texture_o = ft_create_texture_from_file(path, "WE", &new.window);
	new.wall_texture_e = ft_create_texture_from_file(path, "EA", &new.window);
	new.sprite_texture = ft_create_texture_from_file(path, "S", &new.window);
	new.ceil_color = ft_get_color(path, "C");
	new.floor_color = ft_get_color(path, "F");
	new.win_center = window_dimensions.y / 2;
	new.sprites = ft_list();
	new.save = 0;
	new.z_buffer = (double *)malloc(window_dimensions.x * sizeof(double));
	return (new);
}
