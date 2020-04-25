#include "../../../includes/cub3d.h"

t_game ft_game(char *path)
{
    t_game new;
    (void)path;
    /*new.map = ft_minimap(map, MINIMAP_WIDTH, MINIMAP_HEIGHT, ft_vector(MINIMAP_X, MINIMAP_Y, 0));
    new.character = ft_character(ft_vector(0, 0, 0), 60, new.map);
    ft_search_character(&new.map, &new.character);
    new.window = ft_window(win_size, win_size, GAME_NAME);*/
    new.map_show = ft_map_show;
    new.character_move = ft_character_move;
    new.cast_ray = ft_cast_ray;
    new.character_rotate = ft_character_rotate;
    new.character_show = ft_character_show;
    /*new.cam_dist = new.map.nx / 2 / tan(ft_degree_to_rad(FOV / 2));
    new.wall_texture_N = ft_texture(new.window.mlx_ptr, "/home/dess/Bureau/cub3d/textures/stone.xpm");
    new.wall_texture_S = ft_texture(new.window.mlx_ptr, "/home/dess/Bureau/cub3d/textures/grass.xpm");
    new.wall_texture_O = ft_texture(new.window.mlx_ptr, "/home/dess/Bureau/cub3d/textures/metal.xpm");
    new.wall_texture_E = ft_texture(new.window.mlx_ptr, "/home/dess/Bureau/cub3d/textures/wall1.xpm");*/
    return (new);
}
