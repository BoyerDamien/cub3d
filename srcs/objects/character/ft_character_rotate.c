#include "cub3d.h"

void ft_character_rotate(t_game *game, int rotation)
{
    t_vector oldplane;
    t_vector old_orientation;
    double rotation_speed;

    oldplane = game->character.plane;
    old_orientation = game->character.orientation;
    rotation_speed = ft_degree_to_rad(ROTATION);
   if (rotation == 'r'){
        game->character.plane.x = game->character.plane.x * cos(-rotation_speed) - game->character.plane.y * sin(-rotation_speed);
        game->character.plane.y = oldplane.x * sin(-rotation_speed) + game->character.plane.y * cos(-rotation_speed);
        game->character.orientation.x = game->character.orientation.x * cos(-rotation_speed) - game->character.orientation.y * sin(-rotation_speed);
        game->character.orientation.y = old_orientation.x * sin(-rotation_speed) + game->character.orientation.y * cos(-rotation_speed);
    }
    else{
        game->character.plane.x = game->character.plane.x * cos(rotation_speed) - game->character.plane.y * sin(rotation_speed);
        game->character.plane.y = oldplane.x * sin(rotation_speed) + game->character.plane.y * cos(rotation_speed);
        game->character.orientation.x = game->character.orientation.x * cos(rotation_speed) - game->character.orientation.y * sin(rotation_speed);
        game->character.orientation.y = old_orientation.x * sin(rotation_speed) + game->character.orientation.y * cos(rotation_speed);
    
    }   
}