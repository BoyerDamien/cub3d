/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_choose_texture.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/21 15:15:33 by dboyer            #+#    #+#             */
/*   Updated: 2020/04/21 15:26:20 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void ft_choose_texture(t_vector point, t_game *game)
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
        game->actual_text = ft_abs(calcx - calcy) > threshold ? game->wall_texture_O : game->actual_text;
    else if (calcx > calcy && ratiox == 1)
        game->actual_text = ft_abs(calcx - calcy) > threshold ? game->wall_texture_E : game->actual_text;
    else if (calcy > calcx && ratioy == 0)
        game->actual_text = ft_abs(calcx - calcy) > threshold ? game->wall_texture_N : game->actual_text;
    else if (calcy > calcx && ratioy == 1)
        game->actual_text = ft_abs(calcx - calcy) > threshold ? game->wall_texture_S : game->actual_text;
}