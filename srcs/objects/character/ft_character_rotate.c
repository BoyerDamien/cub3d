#include "../../../includes/cub3d.h"


void ft_character_rotate(t_character *character, int rotation)
{
    character->orientation += rotation;
    if (character->orientation < 0)
        character->orientation = 360 + character->orientation;
    else if (character->orientation > 360)
        character->orientation = character->orientation - 360;
}