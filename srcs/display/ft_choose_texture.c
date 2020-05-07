/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_choose_texture.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/21 15:15:33 by dboyer            #+#    #+#             */
/*   Updated: 2020/05/07 17:12:44 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void ft_choose_texture(t_ray *ray, t_game *game, double dist)
{
    double x_hit;

    if (ray->side)
        x_hit = game->character.coordinate.x + dist * ray->direction.x;
    else
        x_hit = game->character.coordinate.y + dist * ray->direction.y;
    
    if (ray->side && ray->step.y >= 0)
        game->actual_text = game->wall_texture_N;
    
    else if (ray->side && ray->step.y < 0)
        game->actual_text = game->wall_texture_S;
    
    else if (!ray->side && ray->step.x >= 0)
        game->actual_text = game->wall_texture_O;
    
    else if (!ray->side && ray->step.x < 0)
        game->actual_text = game->wall_texture_E;
    
    game->text_column = floor((x_hit - floor(x_hit)) * game->actual_text.width);
}