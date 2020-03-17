#include "../../../includes/cub3d.h"


void ft_character_rotate(t_game *game, int rotation)
{
    if (rotation == 'r')
        game->character.orientation -= ft_degree_to_rad(ROTATION);
    else if (rotation == 'l')
        game->character.orientation += ft_degree_to_rad(ROTATION);
}