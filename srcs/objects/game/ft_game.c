#include "../../../includes/cub3d.h"

t_game ft_game(char **map, int win_size[2])
{
    t_game new;
    
    new.map = ft_minimap(map, 200, 200, ft_vector(100, 100, 0));
    new.character = ft_character(ft_vector(0, 0, 0), 90, new.map);
    ft_search_character(&new.map, &new.character);
    new.window = ft_window(win_size, win_size, GAME_NAME);
    new.map_show = ft_map_show;
    return (new);
}