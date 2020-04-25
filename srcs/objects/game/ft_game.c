#include "../../../includes/cub3d.h"

static void finish(t_game *game){
    mlx_destroy_image(game->window.mlx_ptr, game->wall_texture_N.img_ptr);
    mlx_destroy_image(game->window.mlx_ptr, game->wall_texture_S.img_ptr);
	mlx_destroy_image(game->window.mlx_ptr, game->wall_texture_E.img_ptr);
	mlx_destroy_image(game->window.mlx_ptr, game->wall_texture_O.img_ptr);
	mlx_destroy_image(game->window.mlx_ptr, game->window.img.img_ptr);
}


t_game ft_game(char *path)
{
    t_game new;
    t_vector window_dimensions;

    window_dimensions =  ft_get_window_dimensions(path);
    /*new.map = ft_minimap(map, MINIMAP_WIDTH, MINIMAP_HEIGHT, ft_vector(MINIMAP_X, MINIMAP_Y, 0));
    new.character = ft_character(ft_vector(0, 0, 0), 60, new.map);
    ft_search_character(&new.map, &new.character);*/
    new.window = ft_window(window_dimensions.x, window_dimensions.y, GAME_NAME);
    new.map_show = ft_map_show;
    new.character_move = ft_character_move;
    new.cast_ray = ft_cast_ray;
    new.character_rotate = ft_character_rotate;
    new.character_show = ft_character_show;
    //new.cam_dist = new.map.nx / 2 / tan(ft_degree_to_rad(FOV / 2));
    new.wall_texture_N = ft_create_texture_from_file(path, "NO", &new.window);
    new.wall_texture_S = ft_create_texture_from_file(path, "SO", &new.window);
    new.wall_texture_O = ft_create_texture_from_file(path, "WE", &new.window);
    new.wall_texture_E = ft_create_texture_from_file(path, "EA", &new.window);
    new.finish = finish;
    return (new);
}
