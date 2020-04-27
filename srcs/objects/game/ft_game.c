#include "../../../includes/cub3d.h"

static void finish(t_game *game){
    mlx_destroy_image(game->window.mlx_ptr, game->wall_texture_N.img_ptr);
    mlx_destroy_image(game->window.mlx_ptr, game->wall_texture_S.img_ptr);
	mlx_destroy_image(game->window.mlx_ptr, game->wall_texture_E.img_ptr);
	mlx_destroy_image(game->window.mlx_ptr, game->wall_texture_O.img_ptr);
	mlx_destroy_image(game->window.mlx_ptr, game->window.img.img_ptr);
    mlx_destroy_window(game->window.mlx_ptr, game->window.win_ptr);
    game->map.clear(&game->map);
}

static void init_method(t_game *game){

    game->map_show = ft_map_show;
    game->character_move = ft_character_move;
    game->cast_ray = ft_cast_ray;
    game->character_rotate = ft_character_rotate;
    game->character_show = ft_character_show;
}

t_game ft_game(char *path)
{
    t_game new;
    t_vector window_dimensions;
    char **map;
    t_vector size;

    init_method(&new);
    map = ft_map_list_to_char(path);
    window_dimensions =  ft_get_window_dimensions(path);
    size = window_dimensions.mul_scalar(&window_dimensions, 0.1);
    new.map = ft_minimap(map, size.x, size.y, size);
    ft_search_character(&new.map, &new.character);
    new.window = ft_window(window_dimensions.x, window_dimensions.y, GAME_NAME);
    new.wall_texture_N = ft_create_texture_from_file(path, "NO", &new.window);
    new.wall_texture_S = ft_create_texture_from_file(path, "SO", &new.window);
    new.wall_texture_O = ft_create_texture_from_file(path, "WE", &new.window);
    new.wall_texture_E = ft_create_texture_from_file(path, "EA", &new.window);
    new.ceil_color = ft_get_color(path, "C");
    new.floor_color = ft_get_color(path, "F");
    new.finish = finish;
    return (new);
}
