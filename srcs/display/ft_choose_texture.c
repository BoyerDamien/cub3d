/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_choose_texture.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/21 15:15:33 by dboyer            #+#    #+#             */
/*   Updated: 2020/04/28 19:45:14 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void ft_choose_texture(t_vector point, t_game *game, t_vector hit_point)
{
    double ratiox;
    double ratioy;
    double calcx;
    double calcy;
    double threshold;

    ratiox = ((int)point.x + 1 - point.x);
    ratioy = ((int)point.y + 1 - point.y);
    calcx = ft_abs(ratiox - 0.5);
    calcy = ft_abs(ratioy - 0.5);
    ratiox = round(ratiox);
    ratioy = round(ratioy);
    threshold = 0.03;

    if (calcx > calcy && ratiox == 0)
    {
        game->actual_text = ft_abs(calcx - calcy) > threshold ? game->wall_texture_O : game->actual_text;
        game->text_column = (hit_point.y - (int)hit_point.y) * game->actual_text.width;
    }
    else if (calcx > calcy && ratiox == 1)
    {
        game->actual_text = ft_abs(calcx - calcy) > threshold ? game->wall_texture_E : game->actual_text;
        game->text_column = (hit_point.y - (int)hit_point.y) * game->actual_text.width;
    }  
    else if (calcy > calcx && ratioy == 0)
    {
        game->actual_text = ft_abs(calcx - calcy) > threshold ? game->wall_texture_N : game->actual_text;
        game->text_column = (hit_point.x - (int)hit_point.x) * game->actual_text.width;
    }
        
    else if (calcy > calcx && ratioy == 1)
    {
        game->actual_text = ft_abs(calcx - calcy) > threshold ? game->wall_texture_S : game->actual_text;
        game->text_column = (hit_point.x - (int)hit_point.x) * game->actual_text.width;
    }      
}